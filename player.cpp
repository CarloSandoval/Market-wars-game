#include "player.h"

Player::Player(std::string _name, int _cash, int _daysLeft)
{
    name = _name;
    balance = _cash;
    daysLeft = _daysLeft;
    currentCity = nullptr;
}


bool Player::hasMoney()
{
    return (balance > 0);
}

bool Player::hasDaysLeft()
{
    return (daysLeft > 0);
}

Inventory& Player::getInventory()
{
    return *inventory;
}

void Player::setBalance(double _balance)
{
    balance = _balance;
}

double Player::getBalance()
{
    return balance;
}

void Player::displayStatusBar()
{
    std::cout<<"Current City: "<< currentCity->getName()<<".      Balance: "<<balance<<"$,      Days Left: "<<daysLeft<<std::endl<<std::endl;
}

void Player::increaseBalance(int x)
{
    balance += abs(x);
}

void Player::decreaseBalance(int x)
{
    balance -= abs(x);
}
void Player::decreaseDayLeft(int x)
{
    daysLeft -= abs(x);
}



//NEED TO BE FIXED @@@@@@@@@@@@@@@
void Player::setInventory(Inventory* _inventory)
{
    inventory = _inventory;
}
