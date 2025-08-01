#include "login.h"
#include "ui_login.h"
#include "messages.h"
#include <QMessageBox>
#include <QScreen>
#include <QGuiApplication>

Login::Login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainPage)
{
    ui->setupUi(this);
    this->move(QGuiApplication::primaryScreen()->geometry().center() - this->rect().center());
    ui->PasswordEdit->setEchoMode(QLineEdit::Password);
    LoginButton();
    DataCheck();
}

Login::~Login()
{
    delete ui;
}
bool Login::DataCheck(){
    auto mail = ui->EmailEdit->text().toStdString();
    auto password = ui->PasswordEdit->text().toStdString();
    if(mail == "user" and password == "user"){
        return true;
    }
    else{
    return false;
    }
}

void Login::LoginButton(){
    connect(ui->Login, &QPushButton::clicked, this, [this](){
        if (DataCheck() == true){
        Messages *messagesWindow = new Messages();
        messagesWindow->show();
        this->hide();
        }
        else{
            QMessageBox::warning(this, tr("Warning"), tr("Wrong password or username"));
        }

    });
    connect(ui->PasswordEdit, &QLineEdit::returnPressed, this, [this]() {
        ui->Login->click();
    });

};


