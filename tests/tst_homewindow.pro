QT += charts sql core gui widgets

CONFIG += c++17

SOURCES += \
    tst_homewindow.cpp

LIBS += -L$$PWD/../ -lFinTrack

INCLUDEPATH += $$PWD/../
