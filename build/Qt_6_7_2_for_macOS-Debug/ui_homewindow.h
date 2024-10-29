/********************************************************************************
** Form generated from reading UI file 'homewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEWINDOW_H
#define UI_HOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeWindow {
   public:
    QWidget *centralwidget;
    QLineEdit *usernameLineEdit;
    QLabel *label;
    QLineEdit *passwordLineEdit;
    QLabel *label_2;
    QPushButton *registerButton;
    QLabel *statusLabel;
    QPushButton *loginButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HomeWindow) {
        if (HomeWindow->objectName().isEmpty()) HomeWindow->setObjectName("HomeWindow");
        HomeWindow->resize(800, 600);
        centralwidget = new QWidget(HomeWindow);
        centralwidget->setObjectName("centralwidget");
        usernameLineEdit = new QLineEdit(centralwidget);
        usernameLineEdit->setObjectName("usernameLineEdit");
        usernameLineEdit->setGeometry(QRect(240, 70, 151, 21));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 70, 171, 20));
        passwordLineEdit = new QLineEdit(centralwidget);
        passwordLineEdit->setObjectName("passwordLineEdit");
        passwordLineEdit->setGeometry(QRect(240, 110, 151, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 110, 111, 16));
        registerButton = new QPushButton(centralwidget);
        registerButton->setObjectName("registerButton");
        registerButton->setGeometry(QRect(420, 80, 100, 32));
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(80, 220, 671, 41));
        loginButton = new QPushButton(centralwidget);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(320, 140, 100, 32));
        HomeWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HomeWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        HomeWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(HomeWindow);
        statusbar->setObjectName("statusbar");
        HomeWindow->setStatusBar(statusbar);

        retranslateUi(HomeWindow);

        QMetaObject::connectSlotsByName(HomeWindow);
    }  // setupUi

    void retranslateUi(QMainWindow *HomeWindow) {
        HomeWindow->setWindowTitle(QCoreApplication::translate("HomeWindow", "HomeWindow", nullptr));
        label->setText(QCoreApplication::translate(
            "HomeWindow",
            "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\270\320\274\321\217 "
            "\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217:",
            nullptr));
        label_2->setText(QCoreApplication::translate("HomeWindow",
                                                     "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 "
                                                     "\320\277\320\260\321\200\320\276\320\273\321\214:",
                                                     nullptr));
        registerButton->setText(QCoreApplication::translate(
            "HomeWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217",
            nullptr));
        statusLabel->setText(QString());
        loginButton->setText(
            QCoreApplication::translate("HomeWindow", "\320\222\320\276\320\271\321\202\320\270", nullptr));
    }  // retranslateUi
};

namespace Ui {
class HomeWindow : public Ui_HomeWindow {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_HOMEWINDOW_H
