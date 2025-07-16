#include "Messages.h"
#include "ui_Messages.h"
#include <QMessageBox>

Messages::Messages(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Messages)
{
    ui->setupUi(this);
    SetConnections();
}

Messages::~Messages()
{
    delete ui;
}

void Messages::SetConnections(){
    connect(ui->EatButton, &QPushButton::clicked, this, [this](){
    QMessageBox::StandardButton reply; reply = QMessageBox::question(this, "Eat", "Bring in room food?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
    } else {
    }
});
    connect(ui->PlayButton, &QPushButton::clicked, this, [this](){
    QMessageBox::StandardButton reply; reply = QMessageBox::question(this, "Play", "Reserve tennis play room?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
    } else {
    }
});
    connect(ui->SleepButton, &QPushButton::clicked, this, [this](){
    QMessageBox::StandardButton reply;reply = QMessageBox::question(this, "Sleep", "Do not disturb?",QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
    } else {
    }
});

    connect(ui->OutButton, &QPushButton::clicked, this, [this](){
    QMessageBox::StandardButton reply;reply = QMessageBox::question(this, "Leave Room", "Leaving Room?",QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
    } else {
    }
});   
}
