QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    caja.cpp \
    compras.cpp \
    inventario.cpp \
    main.cpp \
    mainwindow.cpp \
    producto.cpp \
    ventas.cpp

HEADERS += \
    caja.h \
    compras.h \
    inventario.h \
    mainwindow.h \
    producto.h \
    ventas.h

FORMS += \
    caja.ui \
    compras.ui \
    inventario.ui \
    mainwindow.ui \
    producto.ui \
    ventas.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
