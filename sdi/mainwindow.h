#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionSave_Text_triggered();
    void on_actionLoad_Text_triggered();
    void on_actionSave_Binary_triggered();
    void on_actionLoad_Binary_triggered();

private:
    Ui::MainWindow *ui;

    void saveTextFile(const QString &filePath);
    void loadTextFile(const QString &filePath);
    void saveBinaryFile(const QString &filePath);
    void loadBinaryFile(const QString &filePath);
};

#endif // MAINWINDOW_H
