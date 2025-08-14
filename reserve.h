#pragma once
#include <QMainWindow>
#include <QDateTime>
#include <QWidget>
namespace Ui {
class Reserve;
}

class Reserve : public QMainWindow
{
    Q_OBJECT

public:
    explicit Reserve(QString start, QString end, QWidget *parent = nullptr);
    ~Reserve();
    void CalendarChecker();
    void xary();

private:
    Ui::Reserve *ui;
    int price = 0;
    QString startDate;
    QString endDate;

};


