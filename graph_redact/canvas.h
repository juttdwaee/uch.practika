#ifndef CANVAS_H
#define CANVAS_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPathItem>
#include <QPen>
#include <stack>
#include "action.h"

class Canvas : public QGraphicsView {
    Q_OBJECT

public:
    enum class DrawMode { None, Rectangle, Ellipse, Circle, Curve };

    Canvas(QGraphicsScene *scene, QWidget *parent = nullptr);
    void setDrawMode(DrawMode mode);
    void setPenColor(const QColor &color);
    QColor penColor() const;
    void undo();
    QJsonArray serializeItems() const;
    void deserializeItems(const QJsonArray &jsonArray);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    bool drawing;
    QPointF startPoint;
    QGraphicsItem *currentItem;
    DrawMode currentDrawMode;
    QPainterPath currentPath;
    QPen currentPen;
    std::stack<Action*> actions;
};

#endif // CANVAS_H
