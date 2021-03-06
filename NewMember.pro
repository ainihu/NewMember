#-------------------------------------------------
#
# Project created by QtCreator 2018-09-08T16:18:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RC_ICONS = myappico.ico
RC_FILE = ./ApplicationIcon.rc

TARGET = NewMember
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    login.cpp \
    signup.cpp \
    rootui.cpp \
    baseclass.cpp \
    userui.cpp

HEADERS += \
        mainwindow.h \
    login.h \
    signup.h \
    rootui.h \
    baseclass.h \
    userui.h

FORMS += \
        mainwindow.ui \
    login.ui \
    signup.ui \
    rootui.ui \
    userui.ui

DISTFILES += \
    ApplicationIcon.rc

RESOURCES += \
    image.qrc
