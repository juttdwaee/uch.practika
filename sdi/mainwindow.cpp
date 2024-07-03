#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QTextStream>
#include <QDataStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSave_Text_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save Text File", "", "Text Files (*.txt)");
    if (!filePath.isEmpty()) {
        saveTextFile(filePath);
    }
}

void MainWindow::on_actionLoad_Text_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Load Text File", "", "Text Files (*.txt)");
    if (!filePath.isEmpty()) {
        loadTextFile(filePath);
    }
}

void MainWindow::on_actionSave_Binary_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save Binary File", "", "Binary Files (*.bin)");
    if (!filePath.isEmpty()) {
        saveBinaryFile(filePath);
    }
}

void MainWindow::on_actionLoad_Binary_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Load Binary File", "", "Binary Files (*.bin)");
    if (!filePath.isEmpty()) {
        loadBinaryFile(filePath);
    }
}

void MainWindow::saveTextFile(const QString &filePath)
{
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << ui->textEdit->toPlainText();
        file.close();
    } else {
        QMessageBox::warning(this, "Error", "Could not open file for writing");
    }
}

void MainWindow::loadTextFile(const QString &filePath)
{
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        ui->textEdit->setPlainText(in.readAll());
        file.close();
    } else {
        QMessageBox::warning(this, "Error", "Could not open file for reading");
    }
}

void MainWindow::saveBinaryFile(const QString &filePath)
{
    QFile file(filePath);
    if (file.open(QIODevice::WriteOnly)) {
        QDataStream out(&file);
        out << ui->textEdit->toPlainText();
        file.close();
    } else {
        QMessageBox::warning(this, "Error", "Could not open file for writing");
    }
}

void MainWindow::loadBinaryFile(const QString &filePath)
{
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream in(&file);
        QString text;
        in >> text;
        ui->textEdit->setPlainText(text);
        file.close();
    } else {
        QMessageBox::warning(this, "Error", "Could not open file for reading");
    }
}
