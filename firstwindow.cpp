#include "firstwindow.h"
#include "ui_firstwindow.h"
#include "selectdate.h"
#include "login.h"
#include <QMessageBox>

FirstWindow::FirstWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FirstWindow)
{
    ui->setupUi(this);
    MenuButtons();
}

FirstWindow::~FirstWindow()
{
    delete ui;
}


void FirstWindow::MenuButtons(){
    connect(ui->SigninButton, &QPushButton::clicked, this, [this]()
    {
        Login *loginWindow = new Login();
        loginWindow->show();
        this->hide();
    });
    connect(ui->ResereveButton, &QPushButton::clicked, this, [this]()
    {
        SelectDate *selectDate = new SelectDate();
        selectDate->show();
        this->hide();
    });
};


