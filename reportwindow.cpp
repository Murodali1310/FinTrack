#include "reportwindow.h"

#include <QBarCategoryAxis>
#include <QBarSeries>
#include <QBarSet>
#include <QChart>
#include <QChartView>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QVector>

#include "ui_reportwindow.h"

ReportWindow::ReportWindow(QWidget *parent) : QDialog(parent), ui(new Ui::ReportWindow) { ui->setupUi(this); }

ReportWindow::~ReportWindow() { delete ui; }

void ReportWindow::on_generateReportButton_clicked() {
    QDate startDate = ui->startDateEdit->date();
    QDate endDate = ui->endDateEdit->date();
    generateReport(startDate, endDate);
}

void ReportWindow::generateReport(const QDate &startDate, const QDate &endDate) {
    QSqlQuery query;
    query.prepare(
        "SELECT category, SUM(amount) FROM transactions "
        "WHERE date BETWEEN :startDate AND :endDate "
        "GROUP BY category");
    query.bindValue(":startDate", startDate);
    query.bindValue(":endDate", endDate);

    if (!query.exec()) {
        QMessageBox::warning(this, "Ошибка", "Не удалось получить данные: " + query.lastError().text());
        return;
    }

    QVector<QString> categories;
    QVector<double> amounts;

    while (query.next()) {
        categories.append(query.value(0).toString());
        amounts.append(query.value(1).toDouble());
    }

    QBarSet *set = new QBarSet("Сумма");
    for (double amount : amounts) { *set << amount; }

    QBarSeries *series = new QBarSeries();
    series->append(set);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Отчет по категориям за выбранный период");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categoriesList;
    for (const QString &category : categories) { categoriesList << category; }
    chart->createDefaultAxes();
    chart->setAxisX(new QBarCategoryAxis, series);
    static_cast<QBarCategoryAxis *>(chart->axisX())->append(categoriesList);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    ui->gridLayout->addWidget(chartView);
}
