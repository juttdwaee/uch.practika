#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QMouseEvent>
#include <QTimer>
#include <QGuiApplication>
#include <QCursor>
#include <QDebug>
#include <QLineEdit>
#include <QMessageBox>

void MainWindow::setupCustomCursorAndHumanLabel() {
    if (this->width() <= 400 || this->height() <= 400) {
        QMessageBox::information(this, "Ошибка", "Сделайте окно больше");
    } else {
        QString cursorImagePath = ":/Pictures/bita_vert.png";
        QPixmap cursorImage(cursorImagePath);
        QSize newSize(100, 100);
        cursorImage = cursorImage.scaled(newSize);
        QCursor customCursor(cursorImage);
        humanLabel = new QLabel(this);
        QPixmap ivan(":/Pictures/zubovich.png");
        humanLabel->setPixmap(ivan.scaled(50,100));
        humanLabel->setScaledContents(true);
        humanLabel->setGeometry(200, 200, 70, 100);
        humanLabel->show();
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, [=]() {
            QPoint cursorPos = mapFromGlobal(QCursor::pos());
            QPoint humanPos = humanLabel->geometry().center();
            if (QLineF(cursorPos, humanPos).length() < 300 && x < 3) {
                QPointF direction = cursorPos - humanPos;
                direction /= qMax(qAbs(direction.x()), qAbs(direction.y()));
                double g = 300 / QLineF(cursorPos, humanPos).length();
                int newX = humanLabel->x() - direction.x() * g;
                int newY = humanLabel->y() - direction.y() * g;
                if ((newX >= 0 && newX <= this->width() - humanLabel->width()) &&
                    (newY >= 0 && newY <= this->height() - humanLabel->height())) {
                    humanLabel->move(newX, newY);
                }
            }
        });
        timer->start(10);
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    x = 0;

    // Создаем объект QPixmap для изображения курсора
    QPixmap cursorPixmap(":/Pictures/bita_vert.png");

    // Масштабируем изображение курсора до нужного размера
    QSize newSize(100, 100); // Новый размер изображения курсора (например, 32x32 пикселей)
    cursorPixmap = cursorPixmap.scaled(newSize);

    // Создаем объект QCursor с помощью QPixmap
    QCursor customCursor(cursorPixmap);

    // Устанавливаем созданный курсор
    setCursor(customCursor);

    setupCustomCursorAndHumanLabel();
}



void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && x < 3 ) {
        QString newCursorImagePath = ":/Pictures/bita_hor(60).png";
        QPixmap newCursorImage(newCursorImagePath);
        QSize newSize(100, 100);
        newCursorImage = newCursorImage.scaled(newSize);
        QCursor newCursor(newCursorImage);
        setCursor(newCursor);
    }
    QMainWindow::mousePressEvent(event);
    QPoint cursorPos = mapFromGlobal(QCursor::pos());
    if (QLineF(cursorPos, humanLabel->geometry().center()).length() < 30 && x == 0) {
        QPixmap ivan(":/Pictures/zubovich1.png");
        humanLabel->setPixmap(ivan.scaled(50,100));
        humanLabel->show();
        x++;
    } else if (QLineF(cursorPos, humanLabel->geometry().center()).length() < 30 && x == 1) {
        QPixmap ivan(":/Pictures/zubovich2.png");
        humanLabel->setPixmap(ivan.scaled(50,100));
        humanLabel->show();
        x++;
    } else if(x == 2) {
        //timer -> stop();
        QPixmap car(":/Pictures/car for levakov.png");
        carLabel->setPixmap(car.scaled(50,100));
        carLabel->setScaledContents(true);
        QPoint humanPos = humanLabel->geometry().center();
        carLabel->setGeometry(700, humanPos.y(), 100, 120);
        carLabel->show();
        QPixmap newCursorImage1(":/Pictures/png.png");
        QSize newSize(100, 100);
        newCursorImage1 = newCursorImage1.scaled(newSize);
        QCursor newCursor1(newCursorImage1);
        setCursor(newCursor1);
        animationTimer = new QTimer(this);
        connect(animationTimer, &QTimer::timeout, this, [=]() {
            int newX1 = carLabel->x() - 2;
            int newY1 = carLabel->y();
            carLabel->move(newX1, newY1);
            QRect carRect = carLabel->geometry();
            QRect humanRect = humanLabel->geometry();
            if (carRect.intersects(humanRect)) {
                humanLabel->hide();
                unsetCursor();
            }
            x++;
        });
        animationTimer->start(20);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && x < 3) {
        QString cursorImagePath = ":/Pictures/bita_vert.png";
        QPixmap cursorImage(cursorImagePath);
        QSize newSize(100, 100);
        cursorImage = cursorImage.scaled(newSize);
        QCursor customCursor(cursorImage);
        setCursor(customCursor);
    }
    QMainWindow::mouseReleaseEvent(event);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QMainWindow::mouseMoveEvent(event);
}

void MainWindow::on_actionStart_triggered()
{
    x = 0;
    setupCustomCursorAndHumanLabel();
}


