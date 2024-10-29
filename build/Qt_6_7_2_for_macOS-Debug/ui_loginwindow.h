/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow {
   public:
    QWidget *centralwidget;
    QPushButton *addIncomeButton;
    QPushButton *addExpenseButton;
    QPushButton *createBudgetButton;
    QPushButton *viewReportsButton;
    QPushButton *filterButton;
    QWidget *reportChartWidget;
    QLabel *statusLabel;
    QListWidget *transactionListWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow) {
        if (LoginWindow->objectName().isEmpty()) LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(752, 552);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        addIncomeButton = new QPushButton(centralwidget);
        addIncomeButton->setObjectName("addIncomeButton");
        addIncomeButton->setGeometry(QRect(60, 60, 121, 32));
        addExpenseButton = new QPushButton(centralwidget);
        addExpenseButton->setObjectName("addExpenseButton");
        addExpenseButton->setGeometry(QRect(240, 60, 121, 32));
        createBudgetButton = new QPushButton(centralwidget);
        createBudgetButton->setObjectName("createBudgetButton");
        createBudgetButton->setGeometry(QRect(230, 110, 131, 32));
        viewReportsButton = new QPushButton(centralwidget);
        viewReportsButton->setObjectName("viewReportsButton");
        viewReportsButton->setGeometry(QRect(470, 60, 131, 32));
        filterButton = new QPushButton(centralwidget);
        filterButton->setObjectName("filterButton");
        filterButton->setGeometry(QRect(70, 180, 71, 32));
        reportChartWidget = new QWidget(centralwidget);
        reportChartWidget->setObjectName("reportChartWidget");
        reportChartWidget->setGeometry(QRect(520, 260, 171, 171));
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(50, 220, 461, 31));
        transactionListWidget = new QListWidget(centralwidget);
        transactionListWidget->setObjectName("transactionListWidget");
        transactionListWidget->setGeometry(QRect(180, 280, 256, 192));
        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 752, 24));
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName("statusbar");
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    }  // setupUi

    void retranslateUi(QMainWindow *LoginWindow) {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "MainWindow", nullptr));
        addIncomeButton->setText(QCoreApplication::translate(
            "LoginWindow",
            "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\264\320\276\321\205\320\276\320\264",
            nullptr));
        addExpenseButton->setText(
            QCoreApplication::translate("LoginWindow",
                                        "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 "
                                        "\321\200\320\260\321\201\321\205\320\276\320\264",
                                        nullptr));
        createBudgetButton->setText(QCoreApplication::translate(
            "LoginWindow",
            "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\261\321\216\320\264\320\266\320\265\321\202",
            nullptr));
        viewReportsButton->setText(
            QCoreApplication::translate("LoginWindow",
                                        "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 "
                                        "\320\276\321\202\321\207\320\265\321\202\320\276\320\262",
                                        nullptr));
        filterButton->setText(
            QCoreApplication::translate("LoginWindow", "\320\244\320\270\320\273\321\214\321\202\321\200", nullptr));
        statusLabel->setText(QString());
    }  // retranslateUi
};

namespace Ui {
class LoginWindow : public Ui_LoginWindow {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_LOGINWINDOW_H
