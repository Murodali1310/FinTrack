#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>

#include "loginwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class HomeWindow;
}
QT_END_NAMESPACE

class HomeWindow : public QMainWindow {
    Q_OBJECT

   public:
    HomeWindow(QWidget *parent = nullptr);
    ~HomeWindow();

   private slots:
    void on_registerButton_clicked();
    void on_loginButton_clicked();

   private:
    Ui::HomeWindow *ui;
    QSqlDatabase db;
    LoginWindow *loginWindow = nullptr;
    bool connectToDatabase();
};

#endif  // HOMEWINDOW_H
