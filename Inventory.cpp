#include "inventory.h"
#include <iostream>
#include <vector>


unsigned long long Inventory::size()
{
    return items->size();
}

Item* Inventory::findItemByIndex(unsigned long _index)
{
    return &items->at(_index);
}

std::ostream& operator<<(std::ostream& os, const Inventory& inventory)
{

    if(inventory.items->size() <= 0)
    {
        os<<"Inventory is empty.\n";
    }
    else
    {
        for (int i=0; i< inventory.items->size(); i++)
        {
            os <<"- ID# "<<i<<" -> "<< inventory.items->at(i) << "\n";
        }
    }

    return os;
}

bool Inventory::isFull()
{
    return ( items->size() >= limit );
}
bool Inventory::isEmpty()
{
    return ( items->size() <= 0 );
}

void Inventory::remove(unsigned long itemIndex)
{
    if(itemIndex < items->size())
    {
        int quantity = items->at(itemIndex).getQuantity();

        if( quantity > 0)
        {
            this->items->at(itemIndex).setQuantity(quantity - 1);
        }
    }
}
