TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    Init_allegro.cpp \
    Points.cpp \
    Keys.cpp \
    Geometary_Functions.cpp
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib/release/ -lallegro
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib/debug/ -lallegro
else:unix: LIBS += -L$$PWD/../../../../../../usr/lib/ -lallegro

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib/release/ -lallegro_dialog
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib/debug/ -lallegro_dialog
else:unix: LIBS += -L$$PWD/../../../../../../usr/lib/ -lallegro_dialog

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib/release/ -lallegro_color
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib/debug/ -lallegro_color
else:unix: LIBS += -L$$PWD/../../../../../../usr/lib/ -lallegro_color

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib/release/ -lallegro_audio
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib/debug/ -lallegro_audio
else:unix: LIBS += -L$$PWD/../../../../../../usr/lib/ -lallegro_audio

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib/release/ -lallegro_image
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib/debug/ -lallegro_image
else:unix: LIBS += -L$$PWD/../../../../../../usr/lib/ -lallegro_image

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib/release/ -lallegro_physfs
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib/debug/ -lallegro_physfs
else:unix: LIBS += -L$$PWD/../../../../../../usr/lib/ -lallegro_physfs

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib/release/ -lallegro_font
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib/debug/ -lallegro_font
else:unix: LIBS += -L$$PWD/../../../../../../usr/lib/ -lallegro_font

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib/release/ -lallegro_acodec
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib/debug/ -lallegro_acodec
else:unix: LIBS += -L$$PWD/../../../../../../usr/lib/ -lallegro_acodec

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib/release/ -lallegro_main
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib/debug/ -lallegro_main
else:unix: LIBS += -L$$PWD/../../../../../../usr/lib/ -lallegro_main

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib/release/ -lallegro_memfile
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib/debug/ -lallegro_memfile
else:unix: LIBS += -L$$PWD/../../../../../../usr/lib/ -lallegro_memfile


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib/release/ -lallegro_primitives
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib/debug/ -lallegro_primitives
else:unix: LIBS += -L$$PWD/../../../../../../usr/lib/ -lallegro_primitives

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib/release/ -lallegro_ttf
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../usr/lib/debug/ -lallegro_ttf
else:unix: LIBS += -L$$PWD/../../../../../../usr/lib/ -lallegro_ttf
INCLUDEPATH += $$PWD/../../../../../../usr/include
DEPENDPATH += $$PWD/../../../../../../usr/include

HEADERS += \
    Init_allegro.h \
    Points.h \
    Keys.h \
    Geometary_Functions.h
