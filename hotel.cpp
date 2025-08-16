#include "hotel.h"
#include "viewanswersdialogue.h"
#include "payment_arca.h"
#include "ui_hotel.h"
#include <QMessageBox>
#include "firstwindow.h"
#include <QScreen>

Hotel::Hotel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Hotel)
{
    ui->setupUi(this);
    this->move(QGuiApplication::primaryScreen()->geometry().center() - this->rect().center());
    SetConnections();
}

Hotel::~Hotel()
{
    delete ui;
}

void Hotel::SetConnections(){
    connect(ui->EatButton, &QPushButton::clicked, this, [this](){
    QMessageBox::StandardButton reply; reply = QMessageBox::question(this, "Eat", "Bring in room food?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        answers_["Bring in room food?"] = "Yes";}
    else {
        answers_["Bring in room food?"] = "No";
    }
});
    connect(ui->PlayButton, &QPushButton::clicked, this, [this](){
    QMessageBox::StandardButton reply; reply = QMessageBox::question(this, "Play", "Reserve tennis play room?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        answers_["Reserve tennis play room?"] = "Yes";
    } else {
        answers_["Reserve tennis play room?"] = "No";
    }
});
    connect(ui->SleepButton, &QPushButton::clicked, this, [this](){
    QMessageBox::StandardButton reply;reply = QMessageBox::question(this, "Sleep", "Do not disturb?",QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        answers_["Do not disturb?"] = "Yes";
    } else {
        answers_["Do not disturb?"] = "No";
    }
});

    connect(ui->OutButton, &QPushButton::clicked, this, [this](){
    QMessageBox::StandardButton reply;reply = QMessageBox::question(this, "Leave Room", "Leaving Room?",QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        answers_["Leaving Room?"] = "Yes";
    } else {
        answers_["Leaving Room?"] = "No";
    }
});
    connect(ui->ViewAnswers, &QPushButton::clicked, this, [this](){
        ViewAnswersDialogue ViewAnswersDialogue{answers_,this};
            ViewAnswersDialogue.setModal(true);
            ViewAnswersDialogue.exec();
    });

    connect(ui->Payment, &QPushButton::clicked, this, [this](){
        PaymentArca PaymentArca{this};
        PaymentArca.setModal(true);
        PaymentArca.exec();
        });
    connect(ui->LogOut, &QPushButton::clicked, this, [this](){
        FirstWindow *FW = new FirstWindow();
        FW->show();
        this->hide();
    });
}
