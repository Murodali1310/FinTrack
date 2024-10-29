/********************************************************************************
** Form generated from reading UI file 'filterdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTERDIALOG_H
#define UI_FILTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_FilterDialog {
   public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FilterDialog) {
        if (FilterDialog->objectName().isEmpty()) FilterDialog->setObjectName("FilterDialog");
        FilterDialog->resize(455, 387);
        buttonBox = new QDialogButtonBox(FilterDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel | QDialogButtonBox::StandardButton::Ok);

        retranslateUi(FilterDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, FilterDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, FilterDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(FilterDialog);
    }  // setupUi

    void retranslateUi(QDialog *FilterDialog) {
        FilterDialog->setWindowTitle(QCoreApplication::translate("FilterDialog", "Dialog", nullptr));
    }  // retranslateUi
};

namespace Ui {
class FilterDialog : public Ui_FilterDialog {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_FILTERDIALOG_H
