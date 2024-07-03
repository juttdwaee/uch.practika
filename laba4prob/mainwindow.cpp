#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // чтобы часы ходили
    QTimer *timer  = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QTime time = QTime::currentTime();
    QPainter painter;
    painter.begin(this);

    painter.setRenderHint(QPainter::Antialiasing);
    // настройка системы координат(перемещаем ее)
    painter.translate(width()/2, height()/2);

    //размещение часов
    int R = 0.7 * qMin(width()/2, height()/2);


    //отрисовка циферблата
    int H = 6;
    QFont font = painter.font();
    for(int i = 0; i < 60; ++i){
        if(i % 5 == 0){
            painter.drawLine(0, R, 0, R - 10);
            font.setPointSize(13);

            //цифры (сделать по горизонтали все)
            painter.setFont(font);
            painter.save();
            painter.translate(0, R + 25);
            painter.rotate(-i * 6);
            painter.drawText(QRect(-15, -15, 30, 30), Qt::AlignHCenter, QString::number(H));
            painter.restore();

            if (H == 12){
                H = 0;
            }
            H = H +1;
        } else{
            painter.drawLine(0, R, 0, R - 4);
        }
        painter.rotate(6.0);
    }

    painter.setPen(Qt::NoPen);
    //отрисовка часовой стрелки
    painter.save();
    QPolygon pol;
    pol << QPoint(-0.05 * R, 0) << QPoint(0.05 * R, 0) << QPoint(0, -0.4 * R);
    painter.setBrush(QColor(52, 113, 235));
    painter.rotate(30 * (time.hour() + time.minute()/60));
    painter.drawPolygon(pol);
    painter.restore();

    //отрисовка минутной стрелки
    painter.save();
    QPolygon pol2;
    pol2 << QPoint(-0.05 * R, 0) << QPoint(0.05 * R, 0) << QPoint(0, -0.7 * R);
    painter.setBrush(QColor(31, 74, 161));
    painter.rotate(6.0 * (time.minute() + time.second()/60));
    painter.drawPolygon(pol2);
    painter.restore();

    //секундная стрелка
    painter.save();
    QPolygon pol3;
    pol3 << QPoint(-0.03 * R, 0) << QPoint(0.03 * R, 0) << QPoint(0, -0.9 * R);
    painter.setBrush(QColor(36, 219, 26));
    painter.drawEllipse(-5, -6, 10, 10);
    painter.rotate(6.0 * time.second());
    painter.drawPolygon(pol3);
    painter.restore();

    painter.end();
}
