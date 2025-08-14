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
    explicit PaymentArca(QWidget *parent); //CreditCard = nullptr
    //void on_Ok_Cancel_accepted();
    ~PaymentArca();

private slots:
    bool on_Ok_Cancel_accepted();

private:
    Ui::PaymentArca *ui;
};
