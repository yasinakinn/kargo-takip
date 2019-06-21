#-------------------------------------------------
#
# Project created by QtCreator 2017-03-15T11:08:59
#
#-------------------------------------------------

QT       += core gui
QT       +=sql


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Formlar
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp\
        kargotakip.cpp \
    gondericiekle.cpp \
    gondericiara.cpp \
    kargoteslim.cpp \
    subeekle.cpp \
    kargohesapla.cpp \
    merkezsubeekle.cpp \
    guzergaholustur.cpp

HEADERS  += kargotakip.h \
    gondericiekle.h \
    gondericiara.h \
    kargoteslim.h \
    subeekle.h \
    kargohesapla.h \
    merkezsubeekle.h \
    guzergaholustur.h

FORMS    += kargotakip.ui \
    gondericiekle.ui \
    gondericiara.ui \
    kargoteslim.ui \
    subeekle.ui \
    kargohesapla.ui \
    merkezsubeekle.ui \
    guzergaholustur.ui


RESOURCES += \
    images.qrc



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Kutuphane/release/ -lKutuphane
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Kutuphane/debug/ -lKutuphane
else:unix: LIBS += -L$$OUT_PWD/../Kutuphane/ -lKutuphane

INCLUDEPATH += $$PWD/../Kutuphane
DEPENDPATH += $$PWD/../Kutuphane
