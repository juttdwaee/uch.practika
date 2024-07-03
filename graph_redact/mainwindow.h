#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "canvas.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void save();
    void load();
    void setDrawRectMode();
    void setDrawEllipseMode();
    void setDrawCircleMode();
    void setDrawCurveMode();
    void choosePenColor();
    void chooseBackgroundColor();
    void undo();

private:
    void createActions();
    void createMenus();

    QGraphicsScene *scene;
    Canvas *canvas;

    QAction *saveAction;
    QAction *loadAction;
    QAction *drawRectAction;
    QAction *drawEllipseAction;
    QAction *drawCircleAction;
    QAction *drawCurveAction;
    QAction *choosePenColorAction;
    QAction *chooseBackgroundColorAction;
    QAction *undoAction;
};

#endif // MAINWINDOW_H
