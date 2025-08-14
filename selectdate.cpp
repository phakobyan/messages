#include "selectdate.h"
#include "ui_selectdate.h"
#include <QScreen>
#include "reserve.h"
#include <QWidget>
#include <QMessageBox>
#include "dbmanager.h"

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



    connect(ui->FindButton, &QPushButton::clicked, this, [this]() {
        QString start = ui->Check_in_Date->date().toString("yyyy-MM-dd");
        QString end = ui->Check_out_Date->date().toString("yyyy-MM-dd");
        RoomCheckResult a = DBManager::hasFreeRoom(start, end);
        if (a == RoomCheckResult::FreeRoomExists or a == RoomCheckResult::NoRooms) {
            Reserve *reserveRoom = new Reserve(start, end);
            reserveRoom->show();
            this->hide();
        } else {
            QMessageBox::warning(this, tr("Warning"), tr("On these dates no rooms are available, please try another date."));
        }
    });


}

SelectDate::~SelectDate()
{
    delete ui;
}
