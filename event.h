#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <vector>

/*
    Event class:

        to improve the way in how the inventory items are randomized in price and quantity.
        the event can have a name, description, and a event type:

        I tried to name some of the most common event that can affect the price of a product
        in a market, and used them as options fo the even type. The effect of the event
        is how it will afect the products on x items, iventory or cities... depending how
        it's implemented.

        event class can be further improved if item class implements categories, so that the event
        can affect products in X categories.

        for now it will target the given item names..
*/


class Event
{


public:

    enum EVENT_TYPE { ECONOMIC_TREND, COMPETITION, PRODUCT_VALUE, DEVELOPMENT_COST, TARGET_CUSTOMERS };

    //effect of event set by default = 0, meaning it has a neutral effect on X items.
    Event(std::string _name, EVENT_TYPE type, int _effect = 0 );

    //for now it will target individual items, expecified on the program, instead of categories
    //these functions return true or false, wether everything went fine or not.
    bool addItemTarget(std::string itemName);
    bool removeItemTarget(std::string itemName);

    EVENT_TYPE getType();
    void setType(EVENT_TYPE _type);

    std::string getDescription();
    void setDescription(std::string _description);


private:

    std::string name;
    std::string description; /* optional */
    EVENT_TYPE type;
    std::vector<std::string> targetItems;



};

#endif // EVENT_H
