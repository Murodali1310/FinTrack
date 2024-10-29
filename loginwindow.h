#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <createbudgetdialog.h>

#include <QMainWindow>
#include <QSqlError>
#include <QSqlQuery>

#include "addtransactiondialog.h"
#include "filterdialog.h"
#include "reportwindow.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow {
    Q_OBJECT

   public:
    explicit LoginWindow(QWidget *parent = nullptr, int userId = -1);
    ~LoginWindow();

   private slots:
    void on_addExpenseButton_clicked();
    void on_addIncomeButton_clicked();
    void on_createBudgetButton_clicked();
    void on_viewReportsButton_clicked();
    void on_filterButton_clicked();
    void loadTransactions();

   private:
    Ui::LoginWindow *ui;
    QSqlDatabase db;
    int currentUserId;
};

#endif  // LOGINWINDOW_H
