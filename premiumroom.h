#pragma once
#include "room.h"

class PremiumRoom: public Room {
public:
    PremiumRoom();
    int getPrice(){
        return price;
    }
private:
    int number_of_guests_;
    int price = 30000;
};

