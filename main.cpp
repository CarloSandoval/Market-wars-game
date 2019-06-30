
#include "gamemanager.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

/*
    game theory behind price of items is that there is a standar price for items thoughtout the cities,
    and this all only influenced by events. Meaning that item prices is always the same, and changed by
    events occuring in the current city.
*/



using namespace std;

int main()
{
    srand (time(NULL));

    //Main game loop and game flags
    bool isGameOver = false;
    bool hasPlayerWon = false;
    unsigned long playerIndexCity = 1;
    enum MenuOptions { SELL=1, BUY, NEXT_CITY, DISPLAY_INVENTORY };


    //City setup
    std::vector<City>* gameCities  = new std::vector<City>{ City("New York, NY"), City("Concord, NH"), City("Boston, MA"), City("Los Angeles, CA") };

    for (int i=0; i<gameCities->size();i++)
    {
        gameCities->at(i).setInventory(new Inventory(*new std::vector<Item>{Item("Chocolate"), Item("Milk"), Item("Water Bottle")}, 10));
    }

    //player setup
    Player* player =  new Player("Carlos");
    vector<Item> playerItems = vector<Item>{Item("Chocolate", 2.0, 3), Item("Milk", 3.0, 3), Item("Water Bottle", 1.0, 3)};
    Inventory playerInventory = Inventory{playerItems, 10};
    player->setInventory(&playerInventory);
    player->currentCity = &gameCities->front();



    CA::wait();

    while(!isGameOver)
    {
        //Display option menu on a clean window
        CA::clear();

        //display current city info
        player->displayStatusBar();
        CA::ln();
        GameManager::displayMenuOptions();

        //Get user Choise
        MenuOptions userInput = (MenuOptions)CA::promptForInt("",1, 4);

        switch (userInput)
        {
            case SELL:
                //display user Invetory and prompt user for item index to be sold (loop this) //check for invenoty no empty before anything
               if(playerInventory.isEmpty())
               {

                   CA::log("Sorry Your inventory is empty, try buying something first!", CA::ERROR);

               }else{

                   bool isDoneSelling = false;
                   while (!isDoneSelling)
                   {
                       CA::clear();
                       player->displayStatusBar();
                       CA::log("Displaying your inventory: ", CA::GAME_MANAGER);
                       std::cout<<playerInventory<<std::endl;
                       int itemToSellIndex = CA::promptForInt("Enter the Item # that you want to sell: ", 0, 2);

                       Item* itemToSell = playerInventory.findItemByIndex(itemToSellIndex);


                       if(itemToSell->getQuantity() > 0)
                       {
                           std::cout<<"Are you sure you want to sell \""<<itemToSell->getName()<<"\" for "<<itemToSell->getCost()<<"$ ?"<<std::endl;
                           if(CA::promptForBoolean(""))
                           {
                               player->setBalance(player->getBalance() + itemToSell->getCost());
                               itemToSell->setQuantity(itemToSell->getQuantity()-1);
                               std::cout<<"Item \""<<itemToSell->getName()<<"\" was sold for "<<itemToSell->getCost()<<"$ ."<<std::endl;
                           }else{
                               CA::log("Transaction has been canceled.", CA::GAME_MANAGER);
                           }

                       }else{
                           CA::log("DON'T HAVE ENOGUT OF THIS ITEM", CA::ERROR);
                       }

                       isDoneSelling = !CA::promptForBoolean("Do you want to continue Selling?");
                   }
               }

            break;


            case BUY:
            {
                if(playerInventory.isFull() || !player->hasMoney())
                {
                    CA::log("Sorry, You can't buy an Item right now, due to your inventory is full or you don't have enough Money $ ", CA::ERROR);
                }else{

                    Inventory* currentCityInventory = player->currentCity->getInventory();

                    if(currentCityInventory->isEmpty())
                    {
                        CA::log("There is nothing to buy on this City, Try Selling something or going to next City", CA::ERROR);
                    }else{
                        bool isDoneBuying = false;
                        while (!isDoneBuying)
                        {
                            CA::clear();
                            player->displayStatusBar();
                            CA::log("Displaying the City's inventory ", CA::GAME_MANAGER);
                            std::cout<<*currentCityInventory<<std::endl;

                            //
                            int itemToBuyIndex = CA::promptForInt("Enter the Item # that you want to Buy: ", 0, 2);

                            Item* itemToBuy = currentCityInventory->findItemByIndex(itemToBuyIndex);


                            if(itemToBuy->getQuantity() > 0)
                            {
                                std::cout<<"Are you sure you want to Buy \""<<itemToBuy->getName()<<"\" for "<<itemToBuy->getCost()<<"$ ?"<<std::endl;
                                if(CA::promptForBoolean(""))
                                {
                                    player->decreaseBalance(itemToBuy->getCost());
                                    itemToBuy->decreaseQuantityBy(1);
                                    /*
                                        because same items use same index so far, im going to use index to indecate item on any inventory (as a map data structur with vector<> instead)
                                    */

                                    playerInventory.findItemByIndex(itemToBuyIndex)->increaseQuantityBy(1);

                                    std::cout<<"Item \""<<itemToBuy->getName()<<"\" was bought for "<<itemToBuy->getCost()<<"$ ."<<std::endl;
                                }else{
                                    CA::log("Transaction has been canceled.", CA::GAME_MANAGER);
                                }

                            }else{
                                CA::log("DON'T HAVE ENOGUT OF THIS ITEM", CA::ERROR);
                            }
                            //

                            isDoneBuying = !CA::promptForBoolean("Do you want to continue Buying?");

                        }
                    }

                }
            }
            break;


            case NEXT_CITY:
            {
                GameManager::movePlayerToNextCity(player, gameCities, playerIndexCity);
                CA::wait();
            }
            break;


            case DISPLAY_INVENTORY:
            {
                CA::clear();
                CA::log("Displaying your Inventory: ", CA::GAME_MANAGER);
                std::cout<<playerInventory<<std::endl;
            }
            break;

        }

        //at the end always check if user lost: if daysLeft <= 0
        //Evaluate wheter or not player wins or looses, after menu loop ends...

        if(!player->hasMoney() || !player->hasDaysLeft())
        {
           isGameOver = true;
           hasPlayerWon = player->hasMoney();
        }
        CA::wait();

    }//exit of game loop

    CA::clear();
    player->displayStatusBar();


    if(hasPlayerWon)
    {
        CA::log("Congratulations You have won the game!!!", CA::GAME_MANAGER);
        CA::log("Printing your stats:", CA::GAME_MANAGER);
        CA::ln();
        player->displayStatusBar();
        std::cout<<player->getInventory()<<std::endl;
        CA::ln();


    }
    else
    {
        CA::log("you have lost!", CA::GAME_MANAGER);
    }


 return 0;
}
