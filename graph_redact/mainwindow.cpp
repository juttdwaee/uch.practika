#include "mainwindow.h"
#include <QMenuBar>
#include <QFileDialog>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), scene(new QGraphicsScene(this)), canvas(new Canvas(scene, this)) {

    setCentralWidget(canvas);

    createActions();
    createMenus();
}

MainWindow::~MainWindow() {}

void MainWindow::createActions() {
    saveAction = new QAction(tr("Save"), this);
    connect(saveAction, &QAction::triggered, this, &MainWindow::save);

    loadAction = new QAction(tr("Load"), this);
    connect(loadAction, &QAction::triggered, this, &MainWindow::load);

    drawRectAction = new QAction(tr("Draw Rectangle"), this);
    connect(drawRectAction, &QAction::triggered, this, &MainWindow::setDrawRectMode);

    drawEllipseAction = new QAction(tr("Draw Ellipse"), this);
    connect(drawEllipseAction, &QAction::triggered, this, &MainWindow::setDrawEllipseMode);

    drawCircleAction = new QAction(tr("Draw Circle"), this);
    connect(drawCircleAction, &QAction::triggered, this, &MainWindow::setDrawCircleMode);

    drawCurveAction = new QAction(tr("Draw Curve"), this);
    connect(drawCurveAction, &QAction::triggered, this, &MainWindow::setDrawCurveMode);

    choosePenColorAction = new QAction(tr("Choose Pen Color"), this);
    connect(choosePenColorAction, &QAction::triggered, this, &MainWindow::choosePenColor);

    chooseBackgroundColorAction = new QAction(tr("Choose Background Color"), this);
    connect(chooseBackgroundColorAction, &QAction::triggered, this, &MainWindow::chooseBackgroundColor);

    undoAction = new QAction(tr("Undo"), this);
    connect(undoAction, &QAction::triggered, this, &MainWindow::undo);
}

void MainWindow::createMenus() {
    QMenu *fileMenu = menuBar()->addMenu(tr("File"));
    fileMenu->addAction(saveAction);
    fileMenu->addAction(loadAction);

    QMenu *drawMenu = menuBar()->addMenu(tr("Draw"));
    drawMenu->addAction(drawRectAction);
    drawMenu->addAction(drawEllipseAction);
    drawMenu->addAction(drawCircleAction);
    drawMenu->addAction(drawCurveAction);

    QMenu *colorMenu = menuBar()->addMenu(tr("Color"));
    colorMenu->addAction(choosePenColorAction);
    colorMenu->addAction(chooseBackgroundColorAction);

    QMenu *editMenu = menuBar()->addMenu(tr("Edit"));
    editMenu->addAction(undoAction);
}

void MainWindow::save() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("JSON Files (*.json)"));
    if (fileName.isEmpty()) return;

    QJsonArray jsonArray = canvas->serializeItems();

    QJsonDocument doc(jsonArray);
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(doc.toJson());
    }
}

void MainWindow::load() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("JSON Files (*.json)"));
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) return;

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonArray jsonArray = doc.array();

    canvas->deserializeItems(jsonArray);
}

void MainWindow::setDrawRectMode() {
    canvas->setDrawMode(Canvas::DrawMode::Rectangle);
}

void MainWindow::setDrawEllipseMode() {
    canvas->setDrawMode(Canvas::DrawMode::Ellipse);
}

void MainWindow::setDrawCircleMode() {
    canvas->setDrawMode(Canvas::DrawMode::Circle);
}

void MainWindow::setDrawCurveMode() {
    canvas->setDrawMode(Canvas::DrawMode::Curve);
}

void MainWindow::choosePenColor() {
    QColor color = QColorDialog::getColor(canvas->penColor(), this, tr("Choose Pen Color"));
    if (color.isValid()) {
        canvas->setPenColor(color);
    }
}

void MainWindow::chooseBackgroundColor() {
    QColor color = QColorDialog::getColor(scene->backgroundBrush().color(), this, tr("Choose Background Color"));
    if (color.isValid()) {
        scene->setBackgroundBrush(color);
    }
}

void MainWindow::undo() {
    canvas->undo();
}
