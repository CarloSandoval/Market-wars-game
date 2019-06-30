#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "city.h"
#include "player.h"
#include "ca.h"

class GameManager
{

private:

    std::vector<City>* cities;


public:
    static unsigned long playerCityIndex;//keeps track of what city goes next and so on.
    enum MenuOptions { SELL=1, BUY, NEXT_CITY, DISPLAY_INVENTORY};
    GameManager();
    static void displayMenuOptions();

    double random(double min, double max)
    {
        return rand();
    }

    static void movePlayerToNextCity(Player* player, std::vector<City>* gameCities, unsigned long& playerCityIndex)
    {
        std::cout<<"movin player to city index: "<<playerCityIndex<<std::endl;
        player->currentCity = &gameCities->at(playerCityIndex);
        playerCityIndex = (playerCityIndex+1) % gameCities->size();
        std::cout<<"city index now is: "<<playerCityIndex<<std::endl;

        player->decreaseBalance(50);
        player->decreaseDayLeft(1);
    }
};

#endif // GAMEMANAGER_H
