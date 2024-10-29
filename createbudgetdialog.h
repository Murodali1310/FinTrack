#ifndef CREATEBUDGETDIALOG_H
#define CREATEBUDGETDIALOG_H

#include <QDialog>
#include <QDoubleSpinBox>
#include <QLineEdit>
#include <QPushButton>

class CreateBudgetDialog : public QDialog {
    Q_OBJECT

   public:
    explicit CreateBudgetDialog(QWidget *parent = nullptr);
    QString getCategory() const;
    double getLimit() const;

   private:
    void setupDialog();

    QLineEdit *categoryEdit;
    QDoubleSpinBox *limitSpinBox;
};

#endif  // CREATEBUDGETDIALOG_H
