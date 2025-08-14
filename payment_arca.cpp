#include <iostream>
#include "creditcard.h"
#include "ui_payment_arca.h"
#include "payment_arca.h"
#include <QString>
#include <QMessageBox>
//#include "dbmanager.h"
//#include "reserve.h"

PaymentArca::PaymentArca(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PaymentArca)
{
    ui->setupUi(this);
    ui->Cvv->setEchoMode(QLineEdit::Password);
    connect(ui->Ok_Cancel, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

PaymentArca::~PaymentArca()
{
    delete ui;
}

bool PaymentArca::on_Ok_Cancel_accepted()
{
    auto tmp_cardnumber = ui->CardNumber->text().toStdString();
    auto tmp_expdate = ui->ExpDate->text().toStdString();
    auto tmp_name = ui->Name->text().toStdString();
    auto tmp_cvv = ui->Cvv->text().toStdString();
    if(tmp_cardnumber.length() == 19 and tmp_expdate.length() == 5 and tmp_expdate[2] == '/' and tmp_cvv.length() == 3){
        CreditCard user(tmp_name,tmp_cardnumber,tmp_expdate,tmp_cvv);
        QMessageBox::information(this, tr("Cool"), tr("Payment Accepted wait message to your email"));
        std::cout << user.name() <<std::endl;
        std::cout << user.card_number() <<std::endl;
        std::cout << user.exp_date() <<std::endl;
        std::cout << user.cvv() <<std::endl;
        accept();
        return true;
    }
    else{
        QMessageBox::warning(this, tr("Warning"), tr("Wrong Data, Try Again."));
        return false;
    }
    return false;

}

