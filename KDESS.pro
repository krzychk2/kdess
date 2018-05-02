TEMPLATE = app

QT += widgets core gui multimediawidgets

#FORMS += mainwindow.ui
SOURCES += main.cpp
SOURCES += kdess.cpp

HEADERS += kdess.h


MOC_DIR = build
OBJECTS_DIR = build
UI_DIR = build

DESTDIR = build
