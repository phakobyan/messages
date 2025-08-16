#pragma once
#include "room.h"

class StandardRoom: public Room {
public:
    StandardRoom();
    int getPrice(){
        return price;
    }
private:
    int number_of_guests_;
    const int price = 120;
};
