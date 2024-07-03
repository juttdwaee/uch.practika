/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *action_2;
    QAction *action_4;
    QAction *action_5;
    QWidget *centralwidget;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *birthday_label;
    QDateEdit *birthday_date;
    QLabel *current_label;
    QDateEdit *current_date;
    QLabel *livedays;
    QLabel *result_label;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1012, 691);
        MainWindow->setMouseTracking(false);
        action = new QAction(MainWindow);
        action->setObjectName("action");
        action_2 = new QAction(MainWindow);
        action_2->setObjectName("action_2");
        action_4 = new QAction(MainWindow);
        action_4->setObjectName("action_4");
        action_5 = new QAction(MainWindow);
        action_5->setObjectName("action_5");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 60, 961, 132));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 20, 576, 81));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        birthday_label = new QLabel(gridLayoutWidget);
        birthday_label->setObjectName("birthday_label");

        gridLayout->addWidget(birthday_label, 0, 0, 1, 1);

        birthday_date = new QDateEdit(gridLayoutWidget);
        birthday_date->setObjectName("birthday_date");
        birthday_date->setStyleSheet(QString::fromUtf8("QDateEdit\n"
"{\n"
"    background-color: white;\n"
"    border-style: solid;\n"
"    border-width: 4px;\n"
"    border-color: rgb(100,100,100);\n"
"    spacing: 5px;\n"
"}\n"
"\n"
"\n"
"QDateEdit::drop-down {\n"
"    image: url(:/new/myapp/cbarrowdn.png);\n"
"    width:50px;\n"
"    height:15px;\n"
"    subcontrol-position: right top;\n"
"    subcontrol-origin:margin;\n"
"    background-color: white;\n"
"    border-style: solid;\n"
"    border-width: 4px;\n"
"    border-color: rgb(100,100,100);\n"
"   spacing: 5px;\n"
"}"));

        gridLayout->addWidget(birthday_date, 0, 1, 1, 1);

        current_label = new QLabel(gridLayoutWidget);
        current_label->setObjectName("current_label");

        gridLayout->addWidget(current_label, 1, 0, 1, 1);

        current_date = new QDateEdit(gridLayoutWidget);
        current_date->setObjectName("current_date");
        current_date->setStyleSheet(QString::fromUtf8("QDateEdit\n"
"{\n"
"    background-color: white;\n"
"    border-style: solid;\n"
"    border-width: 4px;\n"
"    border-color: rgb(100,100,100);\n"
"    spacing: 5px;\n"
"}\n"
"\n"
"\n"
"QDateEdit::drop-down {\n"
"    image: url(:/new/myapp/cbarrowdn.png);\n"
"    width:50px;\n"
"    height:15px;\n"
"    subcontrol-position: right top;\n"
"    subcontrol-origin:margin;\n"
"    background-color: white;\n"
"    border-style: solid;\n"
"    border-width: 4px;\n"
"    border-color: rgb(100,100,100);\n"
"   spacing: 5px;\n"
"}"));

        gridLayout->addWidget(current_date, 1, 1, 1, 1);

        livedays = new QLabel(centralwidget);
        livedays->setObjectName("livedays");
        livedays->setGeometry(QRect(10, 150, 281, 19));
        result_label = new QLabel(centralwidget);
        result_label->setObjectName("result_label");
        result_label->setGeometry(QRect(600, 20, 291, 81));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1012, 25));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menu->addAction(action);
        menu->addAction(action_2);
        menu_2->addSeparator();
        menu_2->addAction(action_4);
        menu_2->addAction(action_5);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        action->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        action_2->setText(QCoreApplication::translate("MainWindow", "\320\236 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\265", nullptr));
        action_4->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
#if QT_CONFIG(shortcut)
        action_4->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        action_5->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
#if QT_CONFIG(shortcut)
        action_5->setShortcut(QCoreApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        label->setText(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\255\320\275\320\265\321\200\320\263\320\270\321\202\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \320\267\320\260\321\200\321\217\320\264:<span style=\" font-size:9pt; font-weight:600; color:#a8162c;\"> \320\272\321\200\320\260\321\201\320\275\321\213\320\271</span> - \321\204\320\270\320\267\320\270\320\276\320\273\320\276\320\263\320\270\321\207\320\265\321\201\320\272\320\270\320\271; <span style=\" font-size:9pt; font-weight:600; color:#152d7c;\">\321\201\320\270\320\275\320\270\320\271</span> - \320\277\321\201\320\270\321\205\320\276"
                        "\320\273\320\276\320\263\320\270\321\207\320\265\321\201\320\272\320\270\320\271; <span style=\" font-size:9pt; font-weight:600; color:#090909;\">\321\207\320\265\321\200\320\275\321\213\320\271</span> - \321\203\320\274\321\201\321\202\320\262\320\265\320\275\320\275\321\213\320\271</p></body></html>", nullptr));
        birthday_label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\321\202\321\203 \321\200\320\276\320\266\320\265\320\275\320\270\321\217:</span></p></body></html>", nullptr));
        current_label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\260\321\202\321\203 \321\200\320\260\321\201\321\207\320\265\321\202\320\260 \320\261\320\270\320\276\321\200\320\270\321\202\320\274\320\260:</span></p></body></html>", nullptr));
        livedays->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\277\321\200\320\276\320\266\320\270\321\202\321\213\321\205 \320\264\320\275\320\265\320\271: ", nullptr));
        result_label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\244\320\270\320\267\320\270\320\276\320\273\320\276\320\263\320\270\321\207\320\265\321\201\320\272\320\270\320\271:	</p><p>\320\237\321\201\320\270\321\205\320\276\320\273\320\276\320\263\320\270\321\207\320\265\321\201\320\272\320\270\320\271:	</p><p>\320\243\320\274\321\201\321\202\320\262\320\265\320\275\320\275\321\213\320\271:	</p></body></html>", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
