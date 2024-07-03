#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <math.h>
#include <QDebug>
#include <fstream>


using namespace std;

int days = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    QTimer *timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10);

    ui->setupUi(this);
    ui->current_date->setDate(QDate::currentDate());
    ui->birthday_date->setDate(QDate::currentDate());
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent* ){
    days = abs(ui->current_date->date().toJulianDay() - ui->birthday_date->date().toJulianDay());

    ui->livedays->setText("Количество прожитых дней: " + QString::number(days));
    QPainter painter;
    painter.begin(this);

    painter.setRenderHint(QPainter::Antialiasing, true);



    QPoint pos = QCursor::pos();
    QPoint pos2 = this->pos();
    int diffx = pos.x()-pos2.x();
    painter.drawLine(diffx, 0,diffx ,height());


    diffx -= width()/2;
    ui->result_label->setText("Физиологический:\t" + QString::number(sin(-diffx*M_PI/23/15)*100) +
                              "\nПсихологический:\t" + QString::number(sin(-diffx*M_PI/28/15)*100) +
                              "\nУмственный:\t\t" + QString::number(sin(-diffx*M_PI/33/15)*100));




    painter.translate(width()/2,height()/2 + 50);
    painter.drawLine(-width(),0,width(),0);

    QPoint point;
    painter.save();
    for(double j = -width()/60, i = -width() / 60; i < width() / 60; i += 0.01){
        j += 0.01;
        point.setX(j*30);


        QPen linepen(Qt::red);
        linepen.setWidth(3);
        painter.setPen(linepen);
        point.setY(sin(-(i+days)*2*M_PI/23)*100);
        painter.drawPoint(point);

        linepen.setColor(Qt::blue);
        painter.setPen(linepen);
        point.setY(sin(-(i+days)*2*M_PI/28)*100);
        painter.drawPoint(point);

        linepen.setColor(QColor(64,38,52));
        painter.setPen(linepen);
        point.setY(sin(-(i+days)*2*M_PI/33)*100);
        painter.drawPoint(point);


    }

    painter.restore();

    for (int j=-width()/60; j <= width()/60; j++){
        if(j == 0){
            painter.save();
            QPen linepen(Qt::black);
            linepen.setWidth(3);
            painter.setPen(linepen);
            QFont font = painter.font();
            font.setPointSize(10);
            painter.setFont(font);
            painter.drawLine(j*30,-20, j*30,20);
            painter.rotate(90);
            QString date= ui->current_date->date().addDays(-j).toString();
            painter.drawText(10, j*30, date);
            painter.restore();
        }
        else{

            painter.drawLine(j*30,-10, j*30,10);


            painter.save();
            painter.rotate(90);
            QString date= ui->current_date->date().addDays(-j).toString();
            painter.drawText(10, j*30, date);
            painter.restore();
        }
    }


    painter.end();

}

void MainWindow::on_action_triggered()
{
    QApplication::quit();
}

void MainWindow::on_action_2_triggered()
{
    QMessageBox::about(this, "О программе", "Эта программа считает биоритмы. Жизнь человека, как и все в природе, подвержено влиянию циклических изменений. Успешность того или иного вида деятельности в каждый момент времени определяется балансом притока и оттока его внутренней энергии. Такой баланс изменяется в соответствии  с циклами биоритмов человека");
}

void MainWindow::on_action_4_triggered()
{
    ofstream out("Outp.txt");
    out << ui -> birthday_date->date().toString().toStdString() << '\n';
    out << ui -> current_date->date().toString().toStdString();
    out.close();
    QMessageBox::information(this, "уведомление", "файл успешно перезаписан");

}


void MainWindow::on_action_5_triggered()
{
    string date1;
    string date2;
    ifstream fin;
    fin.open("input.txt");
    getline(fin, date1);
    getline(fin, date2);
    char* a1 = strcpy(new char[date1.length()+1], date1.c_str());
    char *token = strtok(a1, ".");
    int day1 = stoi(token);
    char *token1 = strtok(NULL, ".");
    int month1 = stoi(token1);
    char *token2 = strtok(NULL, ".");
    int year1 = stoi(token2);
    char* a2 = strcpy(new char[date2.length()+1], date2.c_str());
    char *token3 = strtok(a2, ".");
    int day2 = stoi(token3);
    char *token4 = strtok(NULL, ".");
    int month2 = stoi(token4);
    char *token5 = strtok(NULL, ".");
    int year2 = stoi(token5);
    QDate d(year1, month1, day1);
    ui->birthday_date->setDate(d);
    QDate d1(year2, month2, day2);
    ui->current_date->setDate(d1);
    QMessageBox::information(this, "Справка", "Даты успешно изменены на даты из файла");
    fin.close();
}

