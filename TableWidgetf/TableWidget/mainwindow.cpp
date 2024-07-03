#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug> // Для отладки

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(new TableModel(this)) {
    ui->setupUi(this);

    ui->tableView->setModel(model);

    connect(ui->saveData, &QAction::triggered, this, &MainWindow::saveData);
    connect(ui->loadData, &QAction::triggered, this, &MainWindow::loadData);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::saveData() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", "XLSX(*.xlsx)");
    if (fileName.isEmpty())
        return;

    if (!model->saveToFile(fileName)) {
        QMessageBox::warning(this, "Error", "Failed to save file");
    } else {
        qDebug() << "File saved successfully:" << fileName;
    }
}

void MainWindow::loadData() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "XLSX(*.xlsx)");
    if (fileName.isEmpty())
        return;

    if (!model->loadFromFile(fileName)) {
        QMessageBox::warning(this, "Error", "Failed to load file");
    } else {
        qDebug() << "File loaded successfully:" << fileName;
    }
}
