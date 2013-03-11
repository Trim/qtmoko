# This is an application
TEMPLATE=app

# The binary name
TARGET=getcal

# This app uses Qtopia
CONFIG+=qtopia

# Build this app as a quicklauncher plugin
# You need to be using the QTOPIA_ADD_APPLICATION/QTOPIA_MAIN macros or this will not work!
CONFIG+=quicklaunch

# Build this project into the singleexec binary
#CONFIG+=singleexec

# Specify the languages that make lupdate should produce .ts files for
STRING_LANGUAGE=en_US
LANGUAGES=en_US de

# Package information (used for qbuild packages)
pkg [
    name=getcal
    desc="Get your calendars"
    license=GPLv3
    version=1.0
    maintainer="Adrien Dorsaz <adrien@adorsaz.ch>"
]

# These are the source files that get built to create the application
FORMS=\
    getcal.ui \
    settingsdialog.ui

HEADERS=\
    getcal.h \
    calsettings.h \
    icalserver.h

SOURCES=\
    main.cpp\
    getcal.cpp \
    calsettings.cpp \
    icalserver.cpp

# SXE information
target [
    hint=sxe
    domain=untrusted
]

# Install the launcher item. The metadata comes from the .desktop file
# and the path here.
desktop [
    hint=desktop nct
    files=getcal.desktop
    path=/apps/Applications
    trtarget=getcal-nct
]

# Install some pictures.
pics [
    hint=pics
    files=pics/*
    path=/pics/getcal
]

# Install help files
help [
    hint=help
    source=help
    files=getcal.html
]

