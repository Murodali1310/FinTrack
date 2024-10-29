#include "filterdialog.h"

#include <QFormLayout>
#include <QPushButton>
#include <QVBoxLayout>

FilterDialog::FilterDialog(QWidget *parent) : QDialog(parent) { setupDialog(); }

void FilterDialog::setupDialog() {
    setWindowTitle("Фильтр транзакций");

    categoryEdit = new QLineEdit(this);
    startDateEdit = new QDateEdit(QDate::currentDate(), this);
    startDateEdit->setCalendarPopup(true);
    endDateEdit = new QDateEdit(QDate::currentDate(), this);
    endDateEdit->setCalendarPopup(true);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("Категория:", categoryEdit);
    formLayout->addRow("Начальная дата:", startDateEdit);
    formLayout->addRow("Конечная дата:", endDateEdit);

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

QString FilterDialog::getCategory() const { return categoryEdit->text(); }

QDate FilterDialog::getStartDate() const { return startDateEdit->date(); }

QDate FilterDialog::getEndDate() const { return endDateEdit->date(); }
