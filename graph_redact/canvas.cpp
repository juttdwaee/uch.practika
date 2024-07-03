#include "canvas.h"
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QJsonArray>
#include <QJsonObject>
#include <QColor>

Canvas::Canvas(QGraphicsScene *scene, QWidget *parent)
    : QGraphicsView(scene, parent), drawing(false), currentItem(nullptr), currentDrawMode(DrawMode::None) {
    currentPen.setColor(Qt::black);
}

void Canvas::setDrawMode(DrawMode mode) {
    currentDrawMode = mode;
}

void Canvas::setPenColor(const QColor &color) {
    currentPen.setColor(color);
}

QColor Canvas::penColor() const {
    return currentPen.color();
}

void Canvas::undo() {
    if (!actions.empty()) {
        Action *lastAction = actions.top();
        lastAction->undo();
        actions.pop();
        delete lastAction;
    }
}

void Canvas::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        drawing = true;
        startPoint = mapToScene(event->pos());

        switch (currentDrawMode) {
        case DrawMode::Rectangle:
            currentItem = scene()->addRect(QRectF(startPoint, QSizeF(0, 0)), currentPen);
            break;
        case DrawMode::Ellipse:
        case DrawMode::Circle:
            currentItem = scene()->addEllipse(QRectF(startPoint, QSizeF(0, 0)), currentPen);
            break;
        case DrawMode::Curve:
            currentPath = QPainterPath(startPoint);
            currentItem = scene()->addPath(currentPath, currentPen);
            break;
        default:
            drawing = false;
            break;
        }
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *event) {
    if (drawing && currentItem) {
        QPointF endPoint = mapToScene(event->pos());
        QRectF newRect(startPoint, endPoint);

        if (currentItem->type() == QGraphicsRectItem::Type) {
            QGraphicsRectItem *rect = qgraphicsitem_cast<QGraphicsRectItem *>(currentItem);
            rect->setRect(newRect);
        } else if (currentItem->type() == QGraphicsEllipseItem::Type) {
            QGraphicsEllipseItem *ellipse = qgraphicsitem_cast<QGraphicsEllipseItem *>(currentItem);
            if (currentDrawMode == DrawMode::Circle) {
                qreal diameter = std::min(newRect.width(), newRect.height());
                ellipse->setRect(QRectF(startPoint, QSizeF(diameter, diameter)));
            } else {
                ellipse->setRect(newRect);
            }
        } else if (currentItem->type() == QGraphicsPathItem::Type) {
            currentPath.lineTo(endPoint);
            QGraphicsPathItem *pathItem = qgraphicsitem_cast<QGraphicsPathItem *>(currentItem);
            pathItem->setPath(currentPath);
        }
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton && drawing) {
        drawing = false;
        if (currentItem) {
            actions.push(new AddItemAction(scene(), currentItem));
        }
        currentItem = nullptr;
    }
}

QJsonArray Canvas::serializeItems() const {
    QJsonArray jsonArray;
    for (QGraphicsItem *item : scene()->items()) {
        QJsonObject obj;
        if (auto rect = qgraphicsitem_cast<QGraphicsRectItem*>(item)) {
            obj["type"] = "rectangle";
            obj["rect"] = QJsonArray({ rect->rect().x(), rect->rect().y(), rect->rect().width(), rect->rect().height() });
            obj["color"] = rect->pen().color().name();
        } else if (auto ellipse = qgraphicsitem_cast<QGraphicsEllipseItem*>(item)) {
            obj["type"] = "ellipse";
            obj["rect"] = QJsonArray({ ellipse->rect().x(), ellipse->rect().y(), ellipse->rect().width(), ellipse->rect().height() });
            obj["color"] = ellipse->pen().color().name();
        } else if (auto pathItem = qgraphicsitem_cast<QGraphicsPathItem*>(item)) {
            obj["type"] = "path";
            QJsonArray pathArray;
            QPainterPath path = pathItem->path();
            for (int i = 0; i < path.elementCount(); ++i) {
                const QPainterPath::Element &element = path.elementAt(i);
                pathArray.append(QJsonArray({ element.x, element.y }));
            }
            obj["path"] = pathArray;
            obj["color"] = pathItem->pen().color().name();
        }
        jsonArray.append(obj);
    }
    return jsonArray;
}

void Canvas::deserializeItems(const QJsonArray &jsonArray) {
    scene()->clear();

    for (const QJsonValue &value : jsonArray) {
        QJsonObject obj = value.toObject();
        QString type = obj["type"].toString();
        QColor color(obj["color"].toString());

        if (type == "rectangle") {
            QJsonArray rectArray = obj["rect"].toArray();
            QRectF rect(rectArray[0].toDouble(), rectArray[1].toDouble(), rectArray[2].toDouble(), rectArray[3].toDouble());
            QGraphicsRectItem *rectItem = scene()->addRect(rect);
            rectItem->setPen(QPen(color));
        } else if (type == "ellipse") {
            QJsonArray rectArray = obj["rect"].toArray();
            QRectF rect(rectArray[0].toDouble(), rectArray[1].toDouble(), rectArray[2].toDouble(), rectArray[3].toDouble());
            QGraphicsEllipseItem *ellipseItem = scene()->addEllipse(rect);
            ellipseItem->setPen(QPen(color));
        } else if (type == "path") {
            QJsonArray pathArray = obj["path"].toArray();
            QPainterPath path;
            for (const QJsonValue &pointValue : pathArray) {
                QJsonArray pointArray = pointValue.toArray();
                QPointF point(pointArray[0].toDouble(), pointArray[1].toDouble());
                path.lineTo(point);
            }
            QGraphicsPathItem *pathItem = scene()->addPath(path);
            pathItem->setPen(QPen(color));
        }
    }
}
