#pragma once
#include "room.h"

class LuxuryRoom : public Room {
public:
    LuxuryRoom();
    int getPrice(){
        return price;
    }
    //static constexpr int price = 40000;
private:
    int number_of_guests_;
    int price = 40000;
};
