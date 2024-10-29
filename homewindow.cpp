#include "homewindow.h"

#include <QDir>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>

#include "ui_homewindow.h"

HomeWindow::HomeWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::HomeWindow) {
    ui->setupUi(this);

    if (!connectToDatabase()) { QMessageBox::critical(this, "Ошибка", "Не удалось подключиться к базе данных."); }
}

HomeWindow::~HomeWindow() { delete ui; }

bool HomeWindow::connectToDatabase() {
    QString databasePath = "/Users/murodali/Projects/FinTrack/finance_management.db";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(databasePath);

    if (!db.open()) { return false; }

    QSqlQuery query;
    query.exec(
        "CREATE TABLE IF NOT EXISTS users ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "username TEXT NOT NULL UNIQUE, "
        "password TEXT NOT NULL)");

    return true;
}

void HomeWindow::on_registerButton_clicked() {
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        ui->statusLabel->setText("Заполните все поля.");
        return;
    }

    if (!db.isOpen()) {
        ui->statusLabel->setText("Ошибка: база данных не открыта.");
        return;
    }

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM users WHERE username = :username");
    checkQuery.bindValue(":username", username);

    if (!checkQuery.exec()) {
        ui->statusLabel->setText("Ошибка при выполнении запроса проверки: " + checkQuery.lastError().text());
        return;
    }

    checkQuery.next();
    int count = checkQuery.value(0).toInt();

    if (count > 0) {
        ui->statusLabel->setText("Пользователь с таким именем уже существует.");
        return;
    }

    QSqlQuery qu;
    qu.prepare("INSERT INTO users (username, password) VALUES (:username, :password)");
    qu.bindValue(":username", username);
    qu.bindValue(":password", password);

    if (qu.exec()) {
        ui->statusLabel->setText("Регистрация прошла успешно!");
    } else {
        ui->statusLabel->setText("Ошибка регистрации: " + qu.lastError().text());
    }
}

void HomeWindow::on_loginButton_clicked() {
    QString username = ui->usernameLineEdit->text();
    QString password = ui->passwordLineEdit->text();

    if (username.isEmpty() || password.isEmpty()) {
        ui->statusLabel->setText("Заполните все поля.");
        return;
    }

    if (!db.isOpen()) {
        ui->statusLabel->setText("Ошибка: база данных не открыта.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT id, password FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (!query.exec()) {
        ui->statusLabel->setText("Ошибка выполнения запроса: " + query.lastError().text());
        return;
    }

    if (query.next()) {
        int userId = query.value(0).toInt();
        QString dbPassword = query.value(1).toString();
        if (dbPassword == password) {
            if (loginWindow == nullptr) { loginWindow = new LoginWindow(this, userId); }
            loginWindow->show();
            this->hide();
        } else {
            ui->statusLabel->setText("Неверный пароль.");
        }
    } else {
        ui->statusLabel->setText("Пользователь не найден.");
    }
}
