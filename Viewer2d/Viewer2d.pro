QT += widgets

TEMPLATE = app

CONFIG += c++17

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    drawwidget.cpp

HEADERS += \
    mainwindow.h \
    drawwidget.h

FORMS += \
    mainwindow.ui

# ==== ВАЖНО: подключение библиотеки PlaneGeometry ====

# Путь к заголовочным файлам
INCLUDEPATH += ../PlaneGeometry

# Путь к собранной статической библиотеке + подключение
LIBS += $$OUT_PWD/../PlaneGeometry/debug/libPlaneGeometry.a
