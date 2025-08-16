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
    const int price = 180;
};

