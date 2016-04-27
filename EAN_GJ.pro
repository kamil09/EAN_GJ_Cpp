#-------------------------------------------------
#
# Project created by QtCreator 2016-04-13T22:28:20
#
#-------------------------------------------------

QT += core gui
QT += widgets
CONFIG += console

LIBS += -L"/usr/lib" -lmpfr
LIBS += -L"/usr/lib" -lgmp
LIBS += -L"/usr/lib" -lboost_program_options

QMAKE_CXXFLAGS += -std=c++11
QMAKE_CXXFLAGS += -static
QMAKE_CXXFLAGS += -m64

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EAN_GJ
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    plik.cpp \
    algorytm.cpp

HEADERS  += mainwindow.h \
    plik.h \
    algorytm.h \
    Interval.h

FORMS    += mainwindow.ui
