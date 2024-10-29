#include "createbudgetdialog.h"

#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

CreateBudgetDialog::CreateBudgetDialog(QWidget *parent) : QDialog(parent) { setupDialog(); }

void CreateBudgetDialog::setupDialog() {
    setWindowTitle("Создать бюджет");

    categoryEdit = new QLineEdit(this);
    limitSpinBox = new QDoubleSpinBox(this);
    limitSpinBox->setRange(0, 1000000);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow("Категория:", categoryEdit);
    formLayout->addRow("Лимит:", limitSpinBox);

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

QString CreateBudgetDialog::getCategory() const { return categoryEdit->text(); }

double CreateBudgetDialog::getLimit() const { return limitSpinBox->value(); }
