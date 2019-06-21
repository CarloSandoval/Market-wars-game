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
    return inventory;
}

void Player::setBalance(int _balance)
{
    balance = _balance;
}

int Player::getBalance()
{
    return balance;
}

void Player::displayStatusBar()
{
    std::cout<<"Current City: "<< currentCity->getName()<<".      Balance: "<<balance<<"$,      Days Left: "<<daysLeft;
}
