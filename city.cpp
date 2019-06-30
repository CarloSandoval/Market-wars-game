#include "city.h"
#include <random>

City::City(std::string n)
{
    cityName = n;
}
//void City::addItem(Item i)
//{
//}
void City::setItems(std::vector<Item> its)
{
    //clear the current items
    //so we can copy in all the new ones
//   items.clear();
//   for(Item it : its)
//   {
//       items.push_back(it);
//   }
}
//Inventory City::getItems()
//{
//    return inventory;
//}
std::string City::getName()
{
    return cityName;
}

void City::addEvent(){

}
