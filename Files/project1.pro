QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AdministratorGUI.cpp \
    AdoptionList.cpp \
    CSVRepo.cpp \
    GUI.cpp \
    HTMLFile.cpp \
    RepoExceptions.cpp \
    UserGUI.cpp \
    Validators.cpp \
    domain.cpp \
    fileRepo.cpp \
    main.cpp \
    mainwindow.cpp \
    repository.cpp \
    service.cpp

HEADERS += \
    AdministratorGUI.h \
    AdoptionList.h \
    CSVRepo.h \
    GUI.h \
    HTMLFile.h \
    RepoExceptions.h \
    UserGUI.h \
    Validators.h \
    domain.h \
    fileRepo.h \
    mainwindow.h \
    repository.h \
    service.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    dogs.csv \
    dogs.html \
    dogs.txt
