#pragma once
#include <QMainWindow>
#include <QPushButton>
#include <QWidget>


namespace Ui {
class MainPage;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private:
    void LoginButton();
    bool DataCheck();
    Ui::MainPage *ui;
};

/*class Check
{
public:
    Check(std::string login, std::string password):
        login_(login),
        password_(password){}

private:
    std::string login_;
    std::string password_;
};*/
