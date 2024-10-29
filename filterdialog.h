#ifndef FILTERDIALOG_H
#define FILTERDIALOG_H

#include <QDateEdit>
#include <QDialog>
#include <QLineEdit>

class FilterDialog : public QDialog {
    Q_OBJECT

   public:
    explicit FilterDialog(QWidget *parent = nullptr);

    QString getCategory() const;
    QDate getStartDate() const;
    QDate getEndDate() const;

   private:
    QLineEdit *categoryEdit;
    QDateEdit *startDateEdit;
    QDateEdit *endDateEdit;

    void setupDialog();
};

#endif  // FILTERDIALOG_H
