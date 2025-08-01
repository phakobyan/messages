#include "reserve.h"
#include "ui_reserve.h"
#include "payment_arca.h"
#include <QScreen>
#include <QGuiApplication>
#include <QDateTime>
#include <QDebug>
#include <QWidget>
#include <QMessageBox>
Reserve::Reserve(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Reserve)
{
    ui->setupUi(this);
    this->move(QGuiApplication::primaryScreen()->geometry().center() - this->rect().center());
    xary();
}

Reserve::~Reserve()
{
    delete ui;
}

void Reserve::xary(){
    connect(ui->Checkout, &QPushButton::clicked, this, [this](){
        PaymentArca PaymentArca{this};
        PaymentArca.setModal(true);
        PaymentArca.exec();
    });
}


void Reserve::CalendarChecker(){

    int price = 0;
    connect(ui->Checkout, &QPushButton::clicked, this, [this](){
        std::string name = ui->Name_R->text().toStdString();
        std::string surename = ui->Surename_R->text().toStdString();
        std::string email = ui->Email_R ->text().toStdString();
        std::string passport = ui->Passport->text().toStdString();
    });


}


