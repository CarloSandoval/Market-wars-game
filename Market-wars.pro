TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Inventory.cpp \
        ca.cpp \
        city.cpp \
        event.cpp \
        gamemanager.cpp \
        item.cpp \
        main.cpp \
        player.cpp

HEADERS += \
    ca.h \
    city.h \
    event.h \
    gamemanager.h \
    inventory.h \
    item.h \
    player.h
