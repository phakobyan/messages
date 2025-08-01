#pragma once

#include <QWidget>

namespace Ui {
class SelectDate;
}

class SelectDate : public QWidget
{
    Q_OBJECT

public:
    explicit SelectDate(QWidget *parent = nullptr);
    ~SelectDate();

private:
    Ui::SelectDate *ui;
};
