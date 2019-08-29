TEMPLATE = subdirs

SUBDIRS += \
    backend \
    tests

tests.depends = backend

CONFIG += c++17

QMAKE_CXXFLAGS += -Wall -pedantic -fPIC -Werror
QMAKE_CFLAGS += -Wall -pedantic -fPIC -Werror
