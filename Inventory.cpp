#include "inventory.h"

Inventory::Inventory()
{
    //setting inventory defaut limit
    invenoty(10);
}

Inventory::Inventory(int _limit)
{
    limit = _limit;
}

