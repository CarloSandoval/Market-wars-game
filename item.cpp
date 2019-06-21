#include "item.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Item& item)
{
    os<<" Name: "<<item.itemName<<", Cost: "<<item.itemUnitCost<<"$, Quantity: "<<item.itemUnitCost;
    return os;
}
