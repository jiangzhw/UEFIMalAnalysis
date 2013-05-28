# -------------------------------------------------
# Project created by QtCreator 2011-01-19T01:15:55
# -------------------------------------------------
QT += sql \
    script \
    scripttools
TARGET = UEFIMalAnalysis
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    qhexedit_p.cpp \
    qhexedit.cpp
HEADERS += mainwindow.h \
    qhexedit.h \
    qhexedit_p.h
FORMS += mainwindow.ui
RC_FILE = description.rc
TRANSLATIONS += trans.ts
RESOURCES += res.qrc
