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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave_Text;
    QAction *actionLoad_Text;
    QAction *actionSave_Binary;
    QAction *actionLoad_Binary;
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(756, 493);
        actionSave_Text = new QAction(MainWindow);
        actionSave_Text->setObjectName("actionSave_Text");
        actionLoad_Text = new QAction(MainWindow);
        actionLoad_Text->setObjectName("actionLoad_Text");
        actionSave_Binary = new QAction(MainWindow);
        actionSave_Binary->setObjectName("actionSave_Binary");
        actionLoad_Binary = new QAction(MainWindow);
        actionLoad_Binary->setObjectName("actionLoad_Binary");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(30, 50, 691, 301));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 756, 21));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName("menuMenu");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionSave_Text);
        menuMenu->addAction(actionLoad_Text);
        menuMenu->addAction(actionSave_Binary);
        menuMenu->addAction(actionLoad_Binary);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionSave_Text->setText(QCoreApplication::translate("MainWindow", "save text", nullptr));
        actionLoad_Text->setText(QCoreApplication::translate("MainWindow", "load text", nullptr));
        actionSave_Binary->setText(QCoreApplication::translate("MainWindow", "save  binary", nullptr));
        actionLoad_Binary->setText(QCoreApplication::translate("MainWindow", "load binary", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "Menu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
