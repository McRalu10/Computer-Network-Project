/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QStackedWidget *pages;
    QWidget *page1;
    QPushButton *admin;
    QCommandLinkButton *guest;
    QPushButton *quit;
    QWidget *login_page;
    QGroupBox *groupBox;
    QLineEdit *username;
    QLineEdit *password;
    QLabel *label_user;
    QLabel *label_pass;
    QPushButton *submit_login;
    QPushButton *back_button;
    QWidget *page2;
    QCommandLinkButton *logout;
    QLabel *welcome_message;
    QLCDNumber *date_time;
    QComboBox *train_ID;
    QSlider *horizontalSlider;
    QLabel *delay;
    QLabel *labe_ID;
    QLabel *label_delay;
    QPushButton *pushButton;
    QWidget *page3;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QCommandLinkButton *departures;
    QCommandLinkButton *arrivals;
    QLabel *schedule_label;
    QPushButton *bactToPage1;
    QWidget *page4;
    QPushButton *backToPage3;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QLabel *label_2;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        MainWindow->setIconSize(QSize(50, 50));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        label->setGeometry(QRect(0, 0, 800, 200));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(0, 0));
        label->setMaximumSize(QSize(16777215, 16777215));
        label->setPixmap(QPixmap(QString::fromUtf8("train.png")));
        label->setScaledContents(true);
        label->setIndent(0);
        pages = new QStackedWidget(centralwidget);
        pages->setObjectName(QString::fromUtf8("pages"));
        pages->setGeometry(QRect(0, 170, 801, 411));
        pages->setStyleSheet(QString::fromUtf8("background-color: rgb(108, 202, 253);"));
        page1 = new QWidget();
        page1->setObjectName(QString::fromUtf8("page1"));
        admin = new QPushButton(page1);
        admin->setObjectName(QString::fromUtf8("admin"));
        admin->setGeometry(QRect(310, 110, 150, 50));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(admin->sizePolicy().hasHeightForWidth());
        admin->setSizePolicy(sizePolicy2);
        admin->setMaximumSize(QSize(16777215, 50));
        admin->setStyleSheet(QString::fromUtf8("font: 75 italic 18pt \"Ubuntu Mono\";\n"
"background-color: rgba(197, 232, 126,1);\n"
""));
        guest = new QCommandLinkButton(page1);
        guest->setObjectName(QString::fromUtf8("guest"));
        guest->setGeometry(QRect(300, 180, 168, 36));
        guest->setStyleSheet(QString::fromUtf8("font: 75 italic 12pt \"Ubuntu Mono\";\n"
"background-color: rgba(197, 232, 126,1);\n"
""));
        quit = new QPushButton(page1);
        quit->setObjectName(QString::fromUtf8("quit"));
        quit->setGeometry(QRect(650, 360, 150, 50));
        quit->setAutoFillBackground(false);
        quit->setStyleSheet(QString::fromUtf8("font: 75 italic 20pt \"Ubuntu Mono\";\n"
"background-color: rgba(197, 232, 126,1);\n"
""));
        quit->setAutoDefault(false);
        pages->addWidget(page1);
        login_page = new QWidget();
        login_page->setObjectName(QString::fromUtf8("login_page"));
        groupBox = new QGroupBox(login_page);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(39, 49, 311, 191));
        username = new QLineEdit(groupBox);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(110, 50, 151, 24));
        password = new QLineEdit(groupBox);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(110, 100, 151, 24));
        label_user = new QLabel(groupBox);
        label_user->setObjectName(QString::fromUtf8("label_user"));
        label_user->setGeometry(QRect(30, 50, 71, 16));
        label_pass = new QLabel(groupBox);
        label_pass->setObjectName(QString::fromUtf8("label_pass"));
        label_pass->setGeometry(QRect(30, 100, 58, 16));
        submit_login = new QPushButton(groupBox);
        submit_login->setObjectName(QString::fromUtf8("submit_login"));
        submit_login->setGeometry(QRect(100, 150, 80, 24));
        submit_login->setStyleSheet(QString::fromUtf8("font: 75 bold italic 14pt \"Ubuntu Mono\";\n"
"background-color: rgba(197, 232, 126,1);\n"
""));
        back_button = new QPushButton(login_page);
        back_button->setObjectName(QString::fromUtf8("back_button"));
        back_button->setGeometry(QRect(10, 370, 80, 30));
        back_button->setStyleSheet(QString::fromUtf8("font: 75 bold italic 12pt \"Ubuntu Mono\";\n"
"background-color: rgba(197, 232, 126,1);\n"
""));
        pages->addWidget(login_page);
        page2 = new QWidget();
        page2->setObjectName(QString::fromUtf8("page2"));
        logout = new QCommandLinkButton(page2);
        logout->setObjectName(QString::fromUtf8("logout"));
        logout->setGeometry(QRect(670, 40, 111, 41));
        logout->setStyleSheet(QString::fromUtf8("font: 75 italic 12pt \"Ubuntu Mono\";\n"
"background-color: rgba(197, 232, 126,1);\n"
""));
        welcome_message = new QLabel(page2);
        welcome_message->setObjectName(QString::fromUtf8("welcome_message"));
        welcome_message->setGeometry(QRect(50, 30, 211, 71));
        welcome_message->setStyleSheet(QString::fromUtf8("font: 75 bold italic 20pt \"Ubuntu Mono\";\n"
""));
        date_time = new QLCDNumber(page2);
        date_time->setObjectName(QString::fromUtf8("date_time"));
        date_time->setGeometry(QRect(20, 300, 751, 91));
        train_ID = new QComboBox(page2);
        train_ID->addItem(QString());
        train_ID->addItem(QString());
        train_ID->addItem(QString());
        train_ID->addItem(QString());
        train_ID->addItem(QString());
        train_ID->addItem(QString());
        train_ID->addItem(QString());
        train_ID->addItem(QString());
        train_ID->addItem(QString());
        train_ID->setObjectName(QString::fromUtf8("train_ID"));
        train_ID->setGeometry(QRect(150, 120, 79, 24));
        horizontalSlider = new QSlider(page2);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(150, 180, 160, 16));
        horizontalSlider->setOrientation(Qt::Horizontal);
        delay = new QLabel(page2);
        delay->setObjectName(QString::fromUtf8("delay"));
        delay->setGeometry(QRect(150, 200, 151, 20));
        delay->setStyleSheet(QString::fromUtf8("font: 75 italic 12pt \"Ubuntu Mono\";\n"
"background-color: rgba(197, 232, 126,1);\n"
""));
        labe_ID = new QLabel(page2);
        labe_ID->setObjectName(QString::fromUtf8("labe_ID"));
        labe_ID->setGeometry(QRect(90, 123, 58, 16));
        labe_ID->setStyleSheet(QString::fromUtf8("font: 75 bold italic 12pt \"Ubuntu Mono\";\n"
""));
        label_delay = new QLabel(page2);
        label_delay->setObjectName(QString::fromUtf8("label_delay"));
        label_delay->setGeometry(QRect(80, 180, 58, 16));
        label_delay->setStyleSheet(QString::fromUtf8("font: 75 bold italic 12pt \"Ubuntu Mono\";\n"
"\n"
""));
        pushButton = new QPushButton(page2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 250, 80, 24));
        pushButton->setStyleSheet(QString::fromUtf8("font: 75 bold italic 14pt \"Ubuntu Mono\";\n"
"background-color: rgba(197, 232, 126,1);\n"
""));
        pages->addWidget(page2);
        page3 = new QWidget();
        page3->setObjectName(QString::fromUtf8("page3"));
        scrollArea = new QScrollArea(page3);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 170, 801, 201));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 799, 199));
        scrollArea->setWidget(scrollAreaWidgetContents);
        departures = new QCommandLinkButton(page3);
        departures->setObjectName(QString::fromUtf8("departures"));
        departures->setGeometry(QRect(20, 40, 221, 41));
        arrivals = new QCommandLinkButton(page3);
        arrivals->setObjectName(QString::fromUtf8("arrivals"));
        arrivals->setGeometry(QRect(20, 80, 211, 41));
        schedule_label = new QLabel(page3);
        schedule_label->setObjectName(QString::fromUtf8("schedule_label"));
        schedule_label->setGeometry(QRect(20, 120, 261, 41));
        schedule_label->setStyleSheet(QString::fromUtf8("font: 75 bold italic 20pt \"Ubuntu Mono\";\n"
"\n"
""));
        schedule_label->setWordWrap(false);
        bactToPage1 = new QPushButton(page3);
        bactToPage1->setObjectName(QString::fromUtf8("bactToPage1"));
        bactToPage1->setGeometry(QRect(0, 380, 80, 30));
        bactToPage1->setStyleSheet(QString::fromUtf8("font: 75 bold italic 12pt \"Ubuntu Mono\";\n"
"background-color: rgba(197, 232, 126,1);\n"
""));
        pages->addWidget(page3);
        page4 = new QWidget();
        page4->setObjectName(QString::fromUtf8("page4"));
        backToPage3 = new QPushButton(page4);
        backToPage3->setObjectName(QString::fromUtf8("backToPage3"));
        backToPage3->setGeometry(QRect(0, 380, 80, 30));
        backToPage3->setStyleSheet(QString::fromUtf8("font: 75 bold italic 12pt \"Ubuntu Mono\";\n"
"background-color: rgba(197, 232, 126,1);\n"
""));
        scrollArea_2 = new QScrollArea(page4);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(9, 40, 781, 321));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 779, 319));
        label_2 = new QLabel(scrollAreaWidgetContents_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 40, 501, 91));
        label_2->setStyleSheet(QString::fromUtf8("font:75 italic 12pt \"Ubuntu Mono&quot\";\n"
"\n"
"\n"
""));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        pages->addWidget(page4);
        MainWindow->setCentralWidget(centralwidget);
        pages->raise();
        label->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        pages->setCurrentIndex(1);
        quit->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        admin->setText(QCoreApplication::translate("MainWindow", "ADMIN LOGIN", nullptr));
        guest->setText(QCoreApplication::translate("MainWindow", "Sign in as Guest", nullptr));
        quit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Sign in ", nullptr));
        label_user->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
        label_pass->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        submit_login->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        back_button->setText(QCoreApplication::translate("MainWindow", "<-- Back", nullptr));
        logout->setText(QCoreApplication::translate("MainWindow", "Log out", nullptr));
        welcome_message->setText(QCoreApplication::translate("MainWindow", "Hello, Admin!", nullptr));
        train_ID->setItemText(0, QCoreApplication::translate("MainWindow", "IR1", nullptr));
        train_ID->setItemText(1, QCoreApplication::translate("MainWindow", "IR2", nullptr));
        train_ID->setItemText(2, QCoreApplication::translate("MainWindow", "IR3", nullptr));
        train_ID->setItemText(3, QCoreApplication::translate("MainWindow", "IR4", nullptr));
        train_ID->setItemText(4, QCoreApplication::translate("MainWindow", "IR5", nullptr));
        train_ID->setItemText(5, QCoreApplication::translate("MainWindow", "RE1", nullptr));
        train_ID->setItemText(6, QCoreApplication::translate("MainWindow", "RE2", nullptr));
        train_ID->setItemText(7, QCoreApplication::translate("MainWindow", "RE3", nullptr));
        train_ID->setItemText(8, QString());

        delay->setText(QCoreApplication::translate("MainWindow", "0 minutes", nullptr));
        labe_ID->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        label_delay->setText(QCoreApplication::translate("MainWindow", "Delay:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Submit", nullptr));
        departures->setText(QCoreApplication::translate("MainWindow", "Check the next hour departures", nullptr));
        arrivals->setText(QCoreApplication::translate("MainWindow", "Check the next hour arrivals", nullptr));
        schedule_label->setText(QCoreApplication::translate("MainWindow", "Today's Schedule:", nullptr));
        bactToPage1->setText(QCoreApplication::translate("MainWindow", "<-- Back", nullptr));
        backToPage3->setText(QCoreApplication::translate("MainWindow", "<-- Back", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Next Hour Trains Info Here", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
