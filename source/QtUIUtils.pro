#-------------------------------------------------
#
# Project created by QtCreator 2014-06-28T14:34:54
#
#-------------------------------------------------

CONFIG = c++11

QT       -= gui
QT       += widgets


TARGET = QtUIUtils
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    checkenablegroup.cpp \
    checkgroup.cpp \
    checkvisibilitygroup.cpp \
    filename.cpp \
    fileselector.cpp \
    logger.cpp

HEADERS += \
    checkenablegroup.h \
    checkgroup.h \
    checkvisibilitygroup.h \
    filename.h \
    fileselector.h \
    logger.h

headersToInstall.files = $$PWD/*.h

unix {
    target.path = /usr/local/lib
    headersToInstall.path = /usr/local/include/$$TARGET
}

INSTALLS += headersToInstall
INSTALLS += target
