QT += widgets

CONFIG += c++17

TARGET = CurrencyConverter

TEMPLATE = app

INCLUDEPATH += src/windows

SOURCES += \
    src/main.cpp \
    src/windows/mainwindow.cpp

HEADERS += \
    src/windows/mainwindow.h

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
