QT += charts

QT += sql

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addtransactiondialog.cpp \
    createbudgetdialog.cpp \
    filterdialog.cpp \
    loginwindow.cpp \
    main.cpp \
    homewindow.cpp \
    reportwindow.cpp

HEADERS += \
    addtransactiondialog.h \
    createbudgetdialog.h \
    filterdialog.h \
    homewindow.h \
    loginwindow.h \
    reportwindow.h

FORMS += \
    addtransactiondialog.ui \
    createbudgetdialog.ui \
    filterdialog.ui \
    homewindow.ui \
    loginwindow.ui \
    reportwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
