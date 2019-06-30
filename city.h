/*
 * Michael Penta
 * A City has a list (vector) of items for selling and buying
 * */

#ifndef CITY_H
#define CITY_H

#include "inventory.h"
#include "event.h"

class City
{


    public:
       City(std::string name);

    //public setters and getters
       Inventory getItems();
       void setItems(std::vector<Item>);

       std::string getName();     

       //add additional items to the city
       void addEvent();

       void setInventory(Inventory* inv){ inventory = inv;}
       Inventory* getInventory(){ return inventory;}

private:
//private data members
   std::string cityName;
   Inventory* inventory;
   std::vector<Event>* events;

 //private member functions for use by other member functions
   double getRandomPercent();
   int getRandomQuantity();
};

#endif // CITY_H
