CONFIG += release
TEMPLATE = lib
TARGET = QKeySequenceOverride
DEPENDPATH += .
INCLUDEPATH += .
INCLUDEPATH += /usr/local/include/qt5/QtCore
INCLUDEPATH += /usr/local/include/qt5/QtGui
INCLUDEPATH += /usr/local/include/qt5/QtWidgets

# Input
SOURCES += override.cpp

QMAKE_LN_SHLIB       = :
