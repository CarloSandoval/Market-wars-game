#include "ca.h"

/*
    CA: for console Assistant,  is a toolbox to make the game more readable
    and easier to manipulate on the console, also for user input sanitation
*/



void CA::ln(){
    std::cout<<std::endl;
}


void CA::clear(){
    system("cls");
}


bool CA::promptForBoolean(std::string str)
{
    bool isInputInvalid = true;
    std::string userInput;
    bool result =false;

    while(isInputInvalid)
    {   std::cout<<str<<std::endl;
        std::cin>>userInput;

        char response = std::toupper(userInput.front());

        if(response == 'Y')
        {
            result = true;
            isInputInvalid = false;
        }
        else if(response == 'N')
        {
            result = false;
            isInputInvalid = false;
        }
        else
        {
            log("Invalid Input, Only \"Yes\" or \"No\".", ERROR);
        }
    }

    return result;
}

int CA::promptForInt(std::string str, int min, int max)
{
    int userInteger;

    std::cout<<str<<std::endl;

    while(!(std::cin >> userInteger) && userInteger >= min && userInteger <= max)
    {
        log("Plese enter a valid number", ERROR);
        std::cin.clear(); // reset failbit
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
    }

    return userInteger;
}


void CA::log(const char* msg, int role)
{
    switch (role)
    {
    case INFO:
        std::cout<<"[INFO] -> : "<<msg<<std::endl;
    break;
    case ERROR:
        std::cout<<"[ERROR] -> : "<<msg<<std::endl;
    break;
    case WARNING:
        std::cout<<"[WARNING] -> : "<<msg<<std::endl;
    break;
    case PLAYER:
        std::cout<<"[PLAYER] -> : "<<msg<<std::endl;
    break;
    case CITY:
        std::cout<<"[CITY] -> : "<<msg<<std::endl;
    break;
    case GAME_MANAGER:
        std::cout<<"[GAME_MANAGER] -> : "<<msg<<std::endl;
    break;
    default:
        std::cout<<"[UNSUPPORTED LEVEL LOG] -> : "<<msg<<std::endl;
        break;
    }
}


void CA::wait()
{
    system("pause");
}
