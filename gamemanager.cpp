#include "gamemanager.h"

GameManager::GameManager()
{

}

void GameManager::displayMenuOptions()
{
    //Display menu options to player
    CA::ln();
    CA::log("Enter the number of the option you want to choose:", CA::GAME_MANAGER);
    CA::log("1. Sell ", CA::GAME_MANAGER);
    CA::log("2. Buy ", CA::GAME_MANAGER);
    CA::log("3. Move next City ", CA::GAME_MANAGER);
    CA::log("4. Display inventory ", CA::GAME_MANAGER);
    CA::ln();
}

