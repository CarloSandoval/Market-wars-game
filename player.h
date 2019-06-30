#ifndef PLAYER_H
#define PLAYER_H



#include "inventory.h"
#include "city.h"

class Player
{

private:

    std::string name;
    Inventory* inventory;
    int daysLeft;
    double balance;


public:
    City* currentCity; //points to one of the game city

    //player is assign 300$ and a week to play the game
    Player(std::string _name, int _cash = 300, int _daysLeft = 7);
    std::string getName();
    Inventory& getInventory();//overloaded to work with << operator for ostream
    void setInventory(Inventory*);

    bool hasMoney();
    bool hasDaysLeft();

    double getBalance();
    void setBalance(double);

    void displayStatusBar();
    void increaseBalance(int x);
    void decreaseBalance(int x);
    void decreaseDayLeft(int x);
};

#endif // PLAYER_H
