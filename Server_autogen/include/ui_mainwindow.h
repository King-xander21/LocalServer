/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *linePort;
    QTextEdit *logOutput;
    QPushButton *btnStart;
    QPushButton *btnStop;
    QLabel *label;
    QLabel *lblStatus;
    QLineEdit *HostPath;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        linePort = new QLineEdit(centralwidget);
        linePort->setObjectName("linePort");
        linePort->setGeometry(QRect(180, 90, 400, 25));
        logOutput = new QTextEdit(centralwidget);
        logOutput->setObjectName("logOutput");
        logOutput->setGeometry(QRect(130, 130, 500, 320));
        btnStart = new QPushButton(centralwidget);
        btnStart->setObjectName("btnStart");
        btnStart->setGeometry(QRect(220, 460, 81, 70));
        btnStop = new QPushButton(centralwidget);
        btnStop->setObjectName("btnStop");
        btnStop->setGeometry(QRect(450, 460, 81, 70));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(250, 30, 80, 17));
        lblStatus = new QLabel(centralwidget);
        lblStatus->setObjectName("lblStatus");
        lblStatus->setGeometry(QRect(340, 30, 80, 17));
        HostPath = new QLineEdit(centralwidget);
        HostPath->setObjectName("HostPath");
        HostPath->setGeometry(QRect(180, 60, 400, 25));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnStart->setText(QCoreApplication::translate("MainWindow", "Start Server", nullptr));
        btnStop->setText(QCoreApplication::translate("MainWindow", "Stop Server", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Server Status", nullptr));
        lblStatus->setText(QCoreApplication::translate("MainWindow", "Offline", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
