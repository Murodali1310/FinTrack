#ifndef REPORTWINDOW_H
#define REPORTWINDOW_H

#include <QDate>
#include <QDialog>

namespace Ui {
class ReportWindow;
}

class ReportWindow : public QDialog {
    Q_OBJECT

   public:
    explicit ReportWindow(QWidget *parent = nullptr);
    ~ReportWindow();

   private slots:
    void on_generateReportButton_clicked();

   private:
    Ui::ReportWindow *ui;
    void generateReport(const QDate &startDate, const QDate &endDate);
};

#endif  // REPORTWINDOW_H
