#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include "item.h"

class Inventory
{
public:

    Inventory(): limit(0), items(nullptr){}
    Inventory(std::vector<Item>& _items, unsigned long _limit): items(&_items), limit(_limit){}

    //to display inventory overload the << operator for ostream as a friend function? or member function?
    void add(Item _item);
    void remove(unsigned long itemIndex);

    unsigned long long size();

    //are this needed?
    bool addItemByIndex(unsigned long);
    bool removeItemByIndex(unsigned long);
    Item* findItemByIndex(unsigned long);
    bool isEmpty();
    bool isFull();

    friend std::ostream& operator<<(std::ostream& os, const Inventory&);

private:

    unsigned long limit;
    std::vector<Item>* items;
};

#endif // INVENTORY_H
