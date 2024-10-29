#include "addtransactiondialog.h"

#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

#include "ui_addtransactiondialog.h"

AddTransactionDialog::AddTransactionDialog(QWidget *parent, const QString &transactionType)
    : QDialog(parent), transactionType(transactionType) {
    setupDialog();
}

void AddTransactionDialog::setupDialog() {
    if (transactionType == "income") {
        setWindowTitle("Добавить доход");
    } else if (transactionType == "expense") {
        setWindowTitle("Добавить расход");
    }

    categoryEdit = new QLineEdit(this);
    amountSpinBox = new QDoubleSpinBox(this);
    amountSpinBox->setRange(0, 1000000);
    dateEdit = new QDateEdit(QDate::currentDate(), this);
    dateEdit->setCalendarPopup(true);
    descriptionEdit = new QLineEdit(this);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("Категория:", categoryEdit);
    formLayout->addRow("Сумма:", amountSpinBox);
    formLayout->addRow("Дата:", dateEdit);
    formLayout->addRow("Описание:", descriptionEdit);

    QPushButton *okButton = new QPushButton("ОК", this);
    QPushButton *cancelButton = new QPushButton("Отмена", this);
    connect(okButton, &QPushButton::clicked, this, &QDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);
}

QString AddTransactionDialog::getCategory() const { return categoryEdit->text(); }

double AddTransactionDialog::getAmount() const { return amountSpinBox->value(); }

QDate AddTransactionDialog::getDate() const { return dateEdit->date(); }

QString AddTransactionDialog::getDescription() const { return descriptionEdit->text(); }
