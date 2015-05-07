#-------------------------------------------------
#
# Project created by QtCreator 2015-05-06T22:45:42
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = DepositCreator
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    model/ratesmatrix.cpp

HEADERS += \
    model/money.h \
    model/ratesmatrix.h \
    model/valute.h \
    templates/deposittemplate.h \
    utils/array.h \
    utils/section.h
