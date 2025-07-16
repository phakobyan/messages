#include "messages.h"
#include "viewanswersdialogue.h"
#include "ui_messages.h"
#include <QMessageBox>

messages::messages(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::messages)
{
    ui->setupUi(this);
    SetConnections();
}

messages::~messages()
{
    delete ui;
}

void messages::SetConnections(){
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


})
        ;}
