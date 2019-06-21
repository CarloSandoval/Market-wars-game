#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "city.h"
#include "player.h"
#include "ca.h"

class GameManager
{

private:

    std::vector<City> cities;


public:
    enum MenuOptions { SELL=1, BUY, NEXT_CITY, DISPLAY_INVENTORY};
    GameManager();
    static void displayMenuOptions();
};

#endif // GAMEMANAGER_H
