/*
 * Item class
 * Michael Penta
 *
 */
#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>     /* srand, rand */
#include <string>



class Item
{
    //encapsulated data members of class
    private:
        std::string itemName;
        double itemUnitCost;

    public:
        int itemQuantity;

        //new C++11 constructor delegation
        Item(std::string name)
            : itemName(name)
        {
            generateRandomCost();
            generateRandomQuantity();
        }
        Item(std::string name, double cost)

            : itemName(name), itemUnitCost(cost) { generateRandomQuantity(); }

        Item(std::string name, double cost, int qty)
        //set default values
            : itemName(name), itemUnitCost(cost), itemQuantity(qty) {}

        //mutators and accessor member functions
        //C++11 you define trival functions in the header (can be any function but really only should be simple ones)
        int getQuantity(){return itemQuantity;}
        void setQuantity(int n){itemQuantity = n;}

        double getCost(){return itemUnitCost;}
        void setCost(double n) {itemUnitCost = n; }

        std::string getName(){ return itemName; }
        void setName(std::string s){itemName = s;}

        friend std::ostream& operator<<(std::ostream& os, const Item&);

        void generateRandomCost()
        {
            itemUnitCost = rand() % 10 + 0;
        }
        void generateRandomQuantity()
        {
            itemQuantity = (int)(rand() % 10 + 0);
        }

        void increaseQuantityBy(int x){ itemQuantity+= abs(x);}

        void decreaseQuantityBy(int x){ itemQuantity = ((itemQuantity-abs(x))<=0)?0:itemQuantity-abs(x);}
};

#endif // ITEM_H
