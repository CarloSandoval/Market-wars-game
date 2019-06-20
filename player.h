#ifndef PLAYER_H
#define PLAYER_H

#include "inventory.h"
#include "city.h"

class Player
{

private:

    std::string name;
    Inventory inventory;
    int daysLeft;
    City* currentCity; //points to one of the game city


public:

    //player is assign 300$ and a week to play the game
    Player(std::string _name, int _cash = 300, int _daysLeft = 7);
    std::string getName();
    Inventory getInvenoty();//overloaded to work with << operator for ostream

};

#endif // PLAYER_H
