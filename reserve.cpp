#include "reserve.h"
#include "ui_reserve.h"
#include "payment_arca.h"
#include <QScreen>
#include <QGuiApplication>
#include <QDateTime>
#include <QDebug>
#include <QWidget>
#include <QMessageBox>
#include "dbmanager.h"
#include <QDialog>
#include <QButtonGroup>



Reserve::Reserve(QString start,QString end, QWidget *parent)
  //  : QDialog(parent), startDate(start), endDate(end) {
  //  setupUi(this);
    : QMainWindow(parent)
    , ui(new Ui::Reserve)
    , startDate(start)
    , endDate(end)
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

    QButtonGroup *roomGroup = new QButtonGroup(this);
    roomGroup->addButton(Reserve::ui->StandardRoom);
    roomGroup->addButton(Reserve::ui->PremiumRoom);
    roomGroup->addButton(Reserve::ui->LuxuryRoom);
    connect(ui->Checkout, &QPushButton::clicked, this, [this](){

        qDebug() << "startDate =" << startDate;
        DBManager db;
        QString name = ui->Name_R->text();
        QString surname = ui->Surename_R->text();
        QString passport = ui->Passport->text();
        QString email = ui->Email_R->text();

        int roomType = 0;
        if (ui->StandardRoom->isChecked()) {
            roomType = 1;
        } else if (ui->PremiumRoom->isChecked()) {
            roomType = 2;
        } else if (ui->LuxuryRoom->isChecked()) {
            roomType = 3;
        } else {
            QMessageBox::warning(this, "Warning", "Choose Room Type");
               return;
        }

        PaymentArca PaymentArca{this};
        PaymentArca.setModal(true);
        PaymentArca.exec();
        const int i = 0;

        db.addRoom(103, startDate, endDate, name, surname, email, passport, i);
    });
}




