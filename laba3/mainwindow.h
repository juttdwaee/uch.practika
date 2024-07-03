#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QLabel>
#include <QPixmap>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mousePressEvent1(QMouseEvent *event);
    void resetGame();
    int x;
    QLabel *humanLabel = new QLabel(this);
    QLabel *carLabel = new QLabel(this);
    QTimer *timer;
    QTimer *animationTimer;
private:
    Ui::MainWindow *ui;
    QCursor *newCursor; // Добавляем указатель на новый курсор
    void setupCustomCursorAndHumanLabel();
protected:
    void mouseMoveEvent(QMouseEvent *event) override;
private slots:
    void on_actionStart_triggered();
};
#endif // MAINWINDOW_H
