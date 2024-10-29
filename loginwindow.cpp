#include "loginwindow.h"

#include <QListWidget>
#include <QMessageBox>

#include "ui_loginwindow.h"
LoginWindow::LoginWindow(QWidget *parent, int userId)
    : QMainWindow(parent), ui(new Ui::LoginWindow), currentUserId(userId) {
    ui->setupUi(this);

    loadTransactions();
    QString databasePath = "/Users/murodali/Projects/FinTrack/finance_management.db";

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(databasePath);

    if (!db.open()) {
        ui->statusLabel->setText("Ошибка открытия базы данных: " + db.lastError().text());
        return;
    } else {
        ui->statusLabel->setText("База данных успешно открыта.");
    }

    QSqlQuery query(db);
    QString createTableQuery =
        "CREATE TABLE IF NOT EXISTS transactions ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "user_id INTEGER NOT NULL, "
        "type TEXT NOT NULL, "
        "category TEXT NOT NULL, "
        "amount REAL NOT NULL, "
        "date DATE NOT NULL, "
        "description TEXT, "
        "FOREIGN KEY (user_id) REFERENCES users(id)"
        ");";

    if (!query.exec(createTableQuery)) {
        ui->statusLabel->setText("Ошибка создания таблицы: " + query.lastError().text());
    } else {
        ui->statusLabel->setText("Таблица успешно создана или уже существует.");
    }

    QString createBudgetTableQuery =
        "CREATE TABLE IF NOT EXISTS budgets ("
        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
        "user_id INTEGER NOT NULL, "
        "category TEXT NOT NULL, "
        "budget_limit REAL NOT NULL, "
        "FOREIGN KEY (user_id) REFERENCES users(id)"
        ");";
    if (!query.exec(createBudgetTableQuery)) {
        qDebug() << "Ошибка создания таблицы budgets:" << query.lastError().text();
    } else {
        qDebug() << "Таблица budgets успешно создана.";
    }
}

LoginWindow::~LoginWindow() { delete ui; }

double getBudgetLimit(int userId, const QString &category) {
    QSqlQuery query;
    query.prepare("SELECT budget_limit FROM budgets WHERE user_id = :user_id AND category = :category");
    query.bindValue(":user_id", userId);
    query.bindValue(":category", category);

    if (query.exec()) {
        if (query.next()) { return query.value(0).toDouble(); }
    } else {
        qDebug() << "Error getting budget limit:" << query.lastError().text();
    }
    return -1;
}

double getTotalExpenses(int userId, const QString &category) {
    QSqlQuery query;
    query.prepare(
        "SELECT SUM(amount) FROM transactions WHERE user_id = :user_id AND category = :category AND type = 'expense'");
    query.bindValue(":user_id", userId);
    query.bindValue(":category", category);

    if (query.exec()) {
        if (query.next()) { return query.value(0).toDouble(); }
    } else {
        qDebug() << "Error getting total expenses:" << query.lastError().text();
    }
    return 0;
}

void LoginWindow::on_addExpenseButton_clicked() {
    AddTransactionDialog *expenseDialog = new AddTransactionDialog(this, "expense");
    if (expenseDialog->exec() == QDialog::Accepted) {
        QString category = expenseDialog->getCategory();
        double amount = expenseDialog->getAmount();
        QDate date = expenseDialog->getDate();
        QString description = expenseDialog->getDescription();

        int userId = currentUserId;

        double budgetLimit = getBudgetLimit(userId, category);
        double totalExpenses = getTotalExpenses(userId, category);

        qDebug() << "Budget limit: " << budgetLimit;
        qDebug() << "Total expenses: " << totalExpenses;

        if (budgetLimit > 0 && (totalExpenses + amount) > budgetLimit) {
            ui->statusLabel->setText("Ошибка: Превышен лимит бюджета для категории " + category);
            return;
        }

        QSqlQuery query;
        query.prepare(
            "INSERT INTO transactions (user_id, type, category, amount, date, description) "
            "VALUES (:user_id, 'expense', :category, :amount, :date, :description)");
        query.bindValue(":user_id", userId);
        query.bindValue(":category", category);
        query.bindValue(":amount", amount);
        query.bindValue(":date", date);
        query.bindValue(":description", description);

        if (!query.exec()) {
            ui->statusLabel->setText("Ошибка добавления расхода: " + query.lastError().text());
        } else {
            ui->statusLabel->setText("Расход успешно добавлен.");
        }
    }
    loadTransactions();
}

void LoginWindow::on_addIncomeButton_clicked() {
    AddTransactionDialog *incomeDialog = new AddTransactionDialog(this, "income");
    if (incomeDialog->exec() == QDialog::Accepted) {
        QString category = incomeDialog->getCategory();
        double amount = incomeDialog->getAmount();
        QDate date = incomeDialog->getDate();
        QString description = incomeDialog->getDescription();

        QSqlQuery query;
        query.prepare(
            "INSERT INTO transactions (user_id, type, category, amount, date, description) "
            "VALUES (:user_id, 'income', :category, :amount, :date, :description)");
        query.bindValue(":user_id", currentUserId);
        query.bindValue(":category", category);
        query.bindValue(":amount", amount);
        query.bindValue(":date", date);
        query.bindValue(":description", description);

        if (!query.exec()) {
            ui->statusLabel->setText("Ошибка добавления дохода: " + query.lastError().text());
        } else {
            ui->statusLabel->setText("Доход успешно добавлен.");
        }
    }
    loadTransactions();
}

void LoginWindow::on_createBudgetButton_clicked() {
    CreateBudgetDialog *budgetDialog = new CreateBudgetDialog(this);
    if (budgetDialog->exec() == QDialog::Accepted) {
        QString category = budgetDialog->getCategory();
        double limit = budgetDialog->getLimit();

        if (category.isEmpty()) {
            ui->statusLabel->setText("Ошибка: категория не может быть пустой.");
            return;
        }

        if (limit <= 0) {
            ui->statusLabel->setText("Ошибка: лимит должен быть больше 0.");
            return;
        }

        QSqlQuery query;
        query.prepare("INSERT INTO budgets (user_id, category, budget_limit) VALUES (:user_id, :category, :limit)");
        query.bindValue(":user_id", currentUserId);
        query.bindValue(":category", category);
        query.bindValue(":limit", limit);

        if (!query.exec()) {
            ui->statusLabel->setText("Ошибка создания бюджета: " + query.lastError().text());
        } else {
            ui->statusLabel->setText("Бюджет успешно создан.");
        }
    }
}

void LoginWindow::on_viewReportsButton_clicked() {
    ReportWindow *reportWindow = new ReportWindow(this);
    reportWindow->show();
}

void LoginWindow::loadTransactions() {
    ui->transactionListWidget->clear();

    qDebug() << "Текущий user_id:" << currentUserId;

    QSqlQuery query;
    query.prepare("SELECT type, category, amount, date, description FROM transactions WHERE user_id = :userId");
    query.bindValue(":userId", currentUserId);

    if (!query.exec()) {
        QMessageBox::warning(this, "Ошибка", "Не удалось получить данные: " + query.lastError().text());
        return;
    } else {
        qDebug() << "Запрос выполнен успешно";
    }

    while (query.next()) {
        QString transaction = QString("Тип: %1, Категория: %2, Сумма: %3, Дата: %4, Описание: %5")
                                  .arg(query.value("type").toString())
                                  .arg(query.value("category").toString())
                                  .arg(query.value("amount").toString())
                                  .arg(query.value("date").toString())
                                  .arg(query.value("description").toString());

        ui->transactionListWidget->addItem(transaction);
    }

    qDebug() << "Загружено транзакций:" << ui->transactionListWidget->count();
}

void LoginWindow::on_filterButton_clicked() {
    FilterDialog filterDialog(this);
    if (filterDialog.exec() == QDialog::Accepted) {
        QString category = filterDialog.getCategory();
        QDate startDate = filterDialog.getStartDate();
        QDate endDate = filterDialog.getEndDate();

        QSqlQuery query;
        query.prepare(
            "SELECT type, category, amount, date, description FROM transactions "
            "WHERE category = :category AND date BETWEEN :startDate AND :endDate");
        query.bindValue(":category", category);
        query.bindValue(":startDate", startDate);
        query.bindValue(":endDate", endDate);

        if (query.exec()) {
            ui->transactionListWidget->clear();
            while (query.next()) {
                QString transactionString = QString("%1 | %2 | %3 | %4 | %5")
                                                .arg(query.value("type").toString())
                                                .arg(query.value("category").toString())
                                                .arg(query.value("amount").toString())
                                                .arg(query.value("date").toString())
                                                .arg(query.value("description").toString());

                ui->transactionListWidget->addItem(transactionString);
            }
        } else {
            ui->statusLabel->setText("Ошибка фильтрации: " + query.lastError().text());
        }
    }
}
