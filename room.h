#pragma once
#include <QMainWindow>
#include <QDateTime>
class Room {
public:
    Room();
    void setGuestName(std::string name){
        name_ = name;
    }
    void setGuestSurename(std::string surename){
        surename_ = surename;
    }
    void setGuestMail(std::string mail){
        mail_=mail;
    }
    void setGuestPassport(std::string passport){
        passport_=passport;
    }
    void setGuestCheck_in_Date(QDate check_in_date){
        check_in_date_=check_in_date;
    }
    void setGuestCheck_out_Date(QDate check_out_date){
        check_out_date_=check_out_date;
    }
    std::string getGuestName(){
        return name_;
    }
    std::string getGuestSurename(){
        return surename_;
    }
    std::string getGuestMail(){
        return mail_;
    }
    std::string getGuestPassport(){
        return passport_;
    }
    QDate getGuestCheck_in_Date(){
        return check_in_date_;
    }
    QDate getGuestCheck_out_Date(){
        return check_out_date_;
    }

    Room(std::string name, std::string surename,std::string mail, std::string passport, QString room_type, QDate check_in_date, QDate check_out_date){
        name_ = name;
        surename_ = surename;
        mail_ = mail;
        passport_ = passport;
        check_in_date_ = check_in_date;
        check_out_date_ = check_out_date;
        room_type_ = room_type;
    }
private:
    std::string name_;
    std::string surename_;
    std::string mail_;
    std::string passport_;
    QDate check_in_date_;
    QDate check_out_date_;
    QString room_type_;
};
