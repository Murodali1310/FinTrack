/********************************************************************************
** Form generated from reading UI file 'reportwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPORTWINDOW_H
#define UI_REPORTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReportWindow {
   public:
    QDateEdit *startDateEdit;
    QDateEdit *endDateEdit;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *generateReportButton;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *ReportWindow) {
        if (ReportWindow->objectName().isEmpty()) ReportWindow->setObjectName("ReportWindow");
        ReportWindow->resize(562, 498);
        startDateEdit = new QDateEdit(ReportWindow);
        startDateEdit->setObjectName("startDateEdit");
        startDateEdit->setGeometry(QRect(80, 30, 110, 22));
        endDateEdit = new QDateEdit(ReportWindow);
        endDateEdit->setObjectName("endDateEdit");
        endDateEdit->setGeometry(QRect(280, 30, 110, 22));
        gridLayoutWidget = new QWidget(ReportWindow);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 120, 531, 351));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        generateReportButton = new QPushButton(ReportWindow);
        generateReportButton->setObjectName("generateReportButton");
        generateReportButton->setGeometry(QRect(390, 60, 151, 32));
        label = new QLabel(ReportWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 30, 58, 16));
        label_2 = new QLabel(ReportWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(240, 30, 58, 16));

        retranslateUi(ReportWindow);

        QMetaObject::connectSlotsByName(ReportWindow);
    }  // setupUi

    void retranslateUi(QDialog *ReportWindow) {
        ReportWindow->setWindowTitle(QCoreApplication::translate("ReportWindow", "Dialog", nullptr));
        generateReportButton->setText(
            QCoreApplication::translate("ReportWindow",
                                        "\320\241\320\263\320\265\320\275\320\265\321\200\320\270\321\200\320\276\320"
                                        "\262\320\260\321\202\321\214 \320\276\321\202\321\207\320\265\321\202",
                                        nullptr));
        label->setText(QCoreApplication::translate("ReportWindow", "\320\276\321\202:", nullptr));
        label_2->setText(QCoreApplication::translate("ReportWindow", "\320\264\320\276:", nullptr));
    }  // retranslateUi
};

namespace Ui {
class ReportWindow : public Ui_ReportWindow {};
}  // namespace Ui

QT_END_NAMESPACE

#endif  // UI_REPORTWINDOW_H
