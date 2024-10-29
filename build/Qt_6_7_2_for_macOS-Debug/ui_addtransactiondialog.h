/********************************************************************************
** Form generated from reading UI file 'addtransactiondialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDTRANSACTIONDIALOG_H
#define UI_ADDTRANSACTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_AddTransactionDialog {
   public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddTransactionDialog) {
        if (AddTransactionDialog->objectName().isEmpty()) AddTransactionDialog->setObjectName("AddTransactionDialog");
        AddTransactionDialog->resize(643, 499);
        buttonBox = new QDialogButtonBox(AddTransactionDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(190, 360, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel | QDialogButtonBox::StandardButton::Ok);

        retranslateUi(AddTransactionDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddTransactionDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddTransactionDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddTransactionDialog);
    }  // setupUi

    void retranslateUi(QDialog *AddTransactionDialog) {
        AddTransactionDialog->setWindowTitle(QCoreApplication::translate("AddTransactionDialog", "Dialog", nullptr));
    }  // retranslateUi
};

namespace Ui {
class AddTransactionDialog : public Ui_AddTransactionDialog {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_ADDTRANSACTIONDIALOG_H
