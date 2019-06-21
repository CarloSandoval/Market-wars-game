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
    void add(Item _item);
    void remove(Item item);

    unsigned long long size();

    //are this needed?
    bool addItemByIndex(unsigned long);
    bool removeItemByIndex(unsigned long);
    Item findItemByIndex(unsigned long);

    friend std::ostream& operator<<(std::ostream& os, const Inventory&);


};

#endif // INVENTORY_H
