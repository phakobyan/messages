#pragma once
#include <QDialog>

namespace Ui {
class PaymentArca;
class CreditCard;
}

class PaymentArca : public QDialog
{
    Q_OBJECT

public:
    explicit PaymentArca(QWidget *parent);//CreditCard = nullptr
    ~PaymentArca();

private slots:
    void on_Ok_Cancel_accepted();

private:
    Ui::PaymentArca *ui;
};
