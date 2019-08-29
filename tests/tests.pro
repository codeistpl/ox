include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        tst_matrix.h \
        tst_ox.h

SOURCES += \
        main.cpp

LIBS += -L$$OUT_PWD/../backend/ -lbackend
