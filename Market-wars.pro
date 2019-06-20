TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Inventory.cpp \
        city.cpp \
        main.cpp \
        player.cpp

HEADERS += \
    city.h \
    inventory.h \
    item.h \
    player.h
