#ifndef CA_H
#define CA_H
#include <iostream>
#include <limits>

class CA{

public:
    enum{
        INFO = 0, ERROR, WARNING, PLAYER, CITY, GAME_MANAGER
    };

    static void ln();
    static void clear();
    static void wait();
    static bool promptForBoolean(std::string str);
    static int promptForInt(std::string str, int min, int max);
    static void log(const char* msg, int role);

};



#endif // CA_H
