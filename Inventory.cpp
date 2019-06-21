#include "inventory.h"
#include <iostream>

Inventory::Inventory()
{
    //setting inventory defaut limit
    Inventory(10);
}

Inventory::Inventory(int _limit)
{
    limit = _limit;
}



unsigned long long Inventory::size()
{
    return items.size();
}

Item Inventory::findItemByIndex(unsigned long _index)
{
    items.at(_index);
}

std::ostream& operator<<(std::ostream& os, const Inventory& inventory)
{
    for(auto elem : inventory.items)
    {
        os << elem << "\n ";
    }

    if(inventory.items.size() <= 0)
    {
        os<<"Your Inventory is empty.\n";
    }
    return os;
}
