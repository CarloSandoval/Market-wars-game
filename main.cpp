
#include "gamemanager.h"

/*
    game theory behind price of items is that there is a standar price for items thoughtout the cities,
    and this all only influenced by events. Meaning that item prices is always the same, and changed by
    events occuring in the current city.

*/

using namespace std;

int main()
{

    //Main game loop and game flags
    bool isGameOver = false;
    bool hasPlayerWon = false;
    enum MenuOptions { SELL=1, BUY, NEXT_CITY, DISPLAY_INVENTORY};


    //player and city setup
    Player player("Carlos");
    std::vector<City> gameCities { City("New York, NY"), City("Concord, NH"), City("Boston, MA"), City("Los Angeles, CA") };
    player.currentCity = &gameCities.front();

    while(!isGameOver)
    {
        //Display option menu on a clean window
        CA::clear();

        //display current city info
        player.displayStatusBar();
        GameManager::displayMenuOptions();

        //Get user Choise
        MenuOptions userInput = (MenuOptions)CA::promptForInt("",1, 4);

        switch (userInput)
        {
            case SELL:
                //display user Invetory and prompt user for item index to be sold (loop this) //check for invenoty no empty before anything
                bool isDoneSelling = false;
                while (!isDoneSelling)
                {
                    CA::clear();
                    player.displayStatusBar();
                    CA::log("Displaying your inventory: ", 1);
                    std::cout<<player.getInventory()<<std::endl;
                    int itemToSellIndex = CA::promptForInt("Enter the Item # that you want to sell: ", 0, (int)player.getInventory().size());

                    //check if item is on stuck
                    Item itemToSell = player.getInventory().findItemByIndex(itemToSellIndex);//when returning need to do by reference instead of copy...
                    if(itemToSell.getQuantity() > 0)
                    {
                        std::cout<<"Are you sure you want to sell \""<<itemToSell.getName()<<"\" for "<<itemToSell.getCost()<<"$ ?"<<std::endl;
                        if(CA::promptForBoolean(""))
                        {
                            player.setBalance(player.getBalance() + itemToSell.getCost());
                            itemToSell.setQuantity(itemToSell.getQuantity()-1);
                            std::cout<<"Item \""<<itemToSell.getName()<<"\" was sold for "<<itemToSell.getCost()<<"$ ."<<std::endl;
                        }else{
                            CA::log("Transaction has been canceled.", 1);
                        }

                    }else{
                        CA::log("DON'T HAVE ENOGUT OF THIS ITEM", 1);
                    }

                    isDoneSelling = CA::promptForBoolean("Do you want to continue Selling?");
                }



            break;

        }






        //at the end always check if user lost: if daysLeft <= 0
        //Evaluate wheter or not player wins or looses, after menu loop ends...
        if(!player.hasMoney() || !player.hasDaysLeft())
        {
           isGameOver = true;
           hasPlayerWon = player.hasMoney();
        }
        CA::wait();

    }


}
