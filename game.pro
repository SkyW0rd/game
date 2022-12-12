#-------------------------------------------------
#
# Project created by QtCreator 2022-10-09T21:29:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = game
TEMPLATE = app


DEFINES += QT_DEPRECATED_WARNINGS



SOURCES += \
        main.cpp \
        mainwindow.cpp \
    game.cpp \
    gameobject.cpp \
    player.cpp \
    ticket.cpp \

HEADERS += \
        mainwindow.h \
    game.h \
    gameobject.h \

FORMS += \
        mainwindow.ui
CONFIG += resources_big

RESOURCES += \
    res/res.qrc
