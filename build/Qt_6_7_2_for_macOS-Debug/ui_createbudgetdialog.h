/********************************************************************************
** Form generated from reading UI file 'createbudgetdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEBUDGETDIALOG_H
#define UI_CREATEBUDGETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_CreateBudgetDialog {
   public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CreateBudgetDialog) {
        if (CreateBudgetDialog->objectName().isEmpty()) CreateBudgetDialog->setObjectName("CreateBudgetDialog");
        CreateBudgetDialog->resize(414, 330);
        buttonBox = new QDialogButtonBox(CreateBudgetDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel | QDialogButtonBox::StandardButton::Ok);

        retranslateUi(CreateBudgetDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, CreateBudgetDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, CreateBudgetDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(CreateBudgetDialog);
    }  // setupUi

    void retranslateUi(QDialog *CreateBudgetDialog) {
        CreateBudgetDialog->setWindowTitle(QCoreApplication::translate("CreateBudgetDialog", "Dialog", nullptr));
    }  // retranslateUi
};

namespace Ui {
class CreateBudgetDialog : public Ui_CreateBudgetDialog {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_CREATEBUDGETDIALOG_H
