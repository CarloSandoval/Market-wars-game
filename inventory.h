#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "item.h"

class Inventory
{

private:

    int limit;
    std::vector<Item> items;


public:

    Inventory();
    Inventory(int);
    //to display inventory overload the << operator for ostream as a friend function? or member function?
    bool addItemByIndex();
    bool removeItemByIndex();
    Item findItemByIndex();


};

#endif // INVENTORY_H
