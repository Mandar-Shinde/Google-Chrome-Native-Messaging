#-------------------------------------------------
#
# Project created by Mandar Shinde 2016-06-06T14:38:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testui

TEMPLATE = app

DEFINES += QT_NO_ICU
SOURCES += main.cpp\
        mainwindow.cpp \
    Worker.cpp

HEADERS  += mainwindow.h \
    Worker.h

FORMS    += mainwindow.ui
