#pragma once
#include "room.h"

class LuxuryRoom : public Room {
public:
    LuxuryRoom();
    int getPrice(){
        return price;
    }
private:
    int number_of_guests_;
    const int price = 250;
};
