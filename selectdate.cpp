#include "selectdate.h"
#include "ui_selectdate.h"
#include <QScreen>
#include "reserve.h"
#include <QWidget>
#include <QMessageBox>

SelectDate::SelectDate(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SelectDate)
{
    ui->setupUi(this);
    this->move(QGuiApplication::primaryScreen()->geometry().center() - this->rect().center());


    QDateTime minDateTime_in = QDateTime(QDateTime::currentDateTime());
    QDateTime minDateTime_out = QDateTime(QDateTime::currentDateTime());
    ui->Check_in_Date->setMinimumDateTime(minDateTime_in);
    ui->Check_out_Date->setMinimumDateTime(minDateTime_out);

    connect(ui->FindButton, &QPushButton::clicked, this, [this](){
        if(true){
        Reserve *reserveRoom = new Reserve();
        reserveRoom->show();
        this->hide();
        }
        else{
            QMessageBox::warning(this, tr("Warning"), tr("on this dates not available rooms, please try another date"));
        }
    });

}

SelectDate::~SelectDate()
{
    delete ui;
}
