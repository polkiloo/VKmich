#-------------------------------------------------
#
# Project created by QtCreator 2014-11-13T15:19:23
#
#-------------------------------------------------

QT       += core gui webkitwidgets network multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VKmich
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    authorization.cpp \
    accessmembers.cpp \
    song.cpp

HEADERS  += mainwindow.h \
    authorization.h \
    accessmembers.h \
    song.h

FORMS    += mainwindow.ui \
    authorization.ui

RESOURCES += \
    controlButtons.qrc
