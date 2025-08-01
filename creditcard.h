#pragma once
#include <QDialog>
class CreditCard
{
public:
    CreditCard();
    CreditCard(std::string name,std::string card_number,std::string exp_date,std::string cvv):
        name_(name),
        card_number_(card_number),
        exp_date_(exp_date),
        cvv_(cvv) {

    }

    const std::string& name() const { return name_; }
    const std::string& card_number() const { return card_number_; }
    const std::string& exp_date() const { return exp_date_; }
    const std::string& cvv() const { return cvv_; }
private:
    std::string name_;
    std::string card_number_;
    std::string exp_date_;
    std::string cvv_;
};
