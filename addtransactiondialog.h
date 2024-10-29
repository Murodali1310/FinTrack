#ifndef ADDTRANSACTIONDIALOG_H
#define ADDTRANSACTIONDIALOG_H

#include <QDateEdit>
#include <QDialog>
#include <QDoubleSpinBox>
#include <QLineEdit>

namespace Ui {
class AddTransactionDialog;
}

class AddTransactionDialog : public QDialog {
    Q_OBJECT

   public:
    explicit AddTransactionDialog(QWidget *parent = nullptr, const QString &transactionType = "income");

    QString getCategory() const;
    double getAmount() const;
    QDate getDate() const;
    QString getDescription() const;

   private:
    QString transactionType;

    QLineEdit *categoryEdit;
    QDoubleSpinBox *amountSpinBox;
    QDateEdit *dateEdit;
    QLineEdit *descriptionEdit;

    void setupDialog();
};

#endif  // ADDTRANSACTIONDIALOG_H
