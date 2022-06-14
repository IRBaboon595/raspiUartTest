/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *com_groupbox;
    QPushButton *com_button;
    QComboBox *com_combobox;
    QLabel *comstate_label;
    QPushButton *echo_button;
    QLabel *service_message;
    QPushButton *com_refresh_button;
    QGroupBox *com_groupbox_2;
    QPushButton *com_button_2;
    QComboBox *com_combobox_2;
    QLabel *comstate_label_2;
    QPushButton *echo_button_2;
    QLabel *service_message_2;
    QPushButton *com_refresh_button_2;
    QGroupBox *com_groupbox_3;
    QLineEdit *sendLineEdit;
    QPushButton *sendPushButton;
    QLineEdit *getLineEdit;
    QSlider *choseSenderSlider;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        com_groupbox = new QGroupBox(centralwidget);
        com_groupbox->setObjectName(QString::fromUtf8("com_groupbox"));
        com_groupbox->setGeometry(QRect(20, 10, 201, 191));
        com_button = new QPushButton(com_groupbox);
        com_button->setObjectName(QString::fromUtf8("com_button"));
        com_button->setGeometry(QRect(100, 30, 91, 21));
        com_combobox = new QComboBox(com_groupbox);
        com_combobox->setObjectName(QString::fromUtf8("com_combobox"));
        com_combobox->setGeometry(QRect(10, 30, 81, 22));
        comstate_label = new QLabel(com_groupbox);
        comstate_label->setObjectName(QString::fromUtf8("comstate_label"));
        comstate_label->setGeometry(QRect(10, 60, 181, 16));
        comstate_label->setAlignment(Qt::AlignCenter);
        echo_button = new QPushButton(com_groupbox);
        echo_button->setObjectName(QString::fromUtf8("echo_button"));
        echo_button->setGeometry(QRect(10, 120, 181, 21));
        service_message = new QLabel(com_groupbox);
        service_message->setObjectName(QString::fromUtf8("service_message"));
        service_message->setGeometry(QRect(10, 150, 181, 16));
        service_message->setAlignment(Qt::AlignCenter);
        com_refresh_button = new QPushButton(com_groupbox);
        com_refresh_button->setObjectName(QString::fromUtf8("com_refresh_button"));
        com_refresh_button->setGeometry(QRect(10, 80, 181, 21));
        com_groupbox_2 = new QGroupBox(centralwidget);
        com_groupbox_2->setObjectName(QString::fromUtf8("com_groupbox_2"));
        com_groupbox_2->setGeometry(QRect(580, 10, 201, 191));
        com_button_2 = new QPushButton(com_groupbox_2);
        com_button_2->setObjectName(QString::fromUtf8("com_button_2"));
        com_button_2->setGeometry(QRect(100, 30, 91, 21));
        com_combobox_2 = new QComboBox(com_groupbox_2);
        com_combobox_2->setObjectName(QString::fromUtf8("com_combobox_2"));
        com_combobox_2->setGeometry(QRect(10, 30, 81, 22));
        comstate_label_2 = new QLabel(com_groupbox_2);
        comstate_label_2->setObjectName(QString::fromUtf8("comstate_label_2"));
        comstate_label_2->setGeometry(QRect(10, 60, 181, 16));
        comstate_label_2->setAlignment(Qt::AlignCenter);
        echo_button_2 = new QPushButton(com_groupbox_2);
        echo_button_2->setObjectName(QString::fromUtf8("echo_button_2"));
        echo_button_2->setGeometry(QRect(10, 120, 181, 21));
        service_message_2 = new QLabel(com_groupbox_2);
        service_message_2->setObjectName(QString::fromUtf8("service_message_2"));
        service_message_2->setGeometry(QRect(10, 150, 181, 16));
        service_message_2->setAlignment(Qt::AlignCenter);
        com_refresh_button_2 = new QPushButton(com_groupbox_2);
        com_refresh_button_2->setObjectName(QString::fromUtf8("com_refresh_button_2"));
        com_refresh_button_2->setGeometry(QRect(10, 80, 181, 21));
        com_groupbox_3 = new QGroupBox(centralwidget);
        com_groupbox_3->setObjectName(QString::fromUtf8("com_groupbox_3"));
        com_groupbox_3->setGeometry(QRect(240, 10, 321, 191));
        sendLineEdit = new QLineEdit(com_groupbox_3);
        sendLineEdit->setObjectName(QString::fromUtf8("sendLineEdit"));
        sendLineEdit->setGeometry(QRect(50, 60, 221, 25));
        sendPushButton = new QPushButton(com_groupbox_3);
        sendPushButton->setObjectName(QString::fromUtf8("sendPushButton"));
        sendPushButton->setGeometry(QRect(120, 90, 89, 25));
        getLineEdit = new QLineEdit(com_groupbox_3);
        getLineEdit->setObjectName(QString::fromUtf8("getLineEdit"));
        getLineEdit->setGeometry(QRect(50, 150, 221, 25));
        choseSenderSlider = new QSlider(com_groupbox_3);
        choseSenderSlider->setObjectName(QString::fromUtf8("choseSenderSlider"));
        choseSenderSlider->setGeometry(QRect(29, 40, 271, 20));
        choseSenderSlider->setOrientation(Qt::Horizontal);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        com_groupbox->setTitle(QCoreApplication::translate("MainWindow", "COM Port USB", nullptr));
        com_button->setText(QCoreApplication::translate("MainWindow", "Open port", nullptr));
        comstate_label->setText(QCoreApplication::translate("MainWindow", "Closed", nullptr));
        echo_button->setText(QCoreApplication::translate("MainWindow", "Echo", nullptr));
        service_message->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
        com_refresh_button->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        com_groupbox_2->setTitle(QCoreApplication::translate("MainWindow", "COM Port UART", nullptr));
        com_button_2->setText(QCoreApplication::translate("MainWindow", "Open port", nullptr));
        comstate_label_2->setText(QCoreApplication::translate("MainWindow", "Closed", nullptr));
        echo_button_2->setText(QCoreApplication::translate("MainWindow", "Echo", nullptr));
        service_message_2->setText(QCoreApplication::translate("MainWindow", "Empty", nullptr));
        com_refresh_button_2->setText(QCoreApplication::translate("MainWindow", "Refresh", nullptr));
        com_groupbox_3->setTitle(QCoreApplication::translate("MainWindow", "Message", nullptr));
        sendPushButton->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
