#-------------------------------------------------
#
# Project created by QtCreator 2018-05-17T18:45:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += multimedia
QT += multimediawidgets

TARGET = RtspPlayerFfmpeg
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    videoplayer.cpp \
    localvdeoplayer.cpp \
    videowindow.cpp

HEADERS += \
        mainwindow.h \
    videoplayer.h \
    localvideoplayer.h \
    videowindow.h

FORMS += \
        mainwindow.ui \
    videowindow.ui


INCLUDEPATH += \
            /Users/taiguangyin/gytai/QT/RtspPlayerFfmpeg/include

LIBS  += \
        /Users/taiguangyin/gytai/QT/RtspPlayerFfmpeg/libs/libavcodec.58.dylib \
        /Users/taiguangyin/gytai/QT/RtspPlayerFfmpeg/libs/libavdevice.58.dylib \
        /Users/taiguangyin/gytai/QT/RtspPlayerFfmpeg/libs/libavfilter.7.dylib \
        /Users/taiguangyin/gytai/QT/RtspPlayerFfmpeg/libs/libavformat.58.dylib \
        /Users/taiguangyin/gytai/QT/RtspPlayerFfmpeg/libs/libavutil.56.dylib \
        /Users/taiguangyin/gytai/QT/RtspPlayerFfmpeg/libs/libpostproc.55.dylib \
        /Users/taiguangyin/gytai/QT/RtspPlayerFfmpeg/libs/libswresample.3.dylib \
        /Users/taiguangyin/gytai/QT/RtspPlayerFfmpeg/libs/libswscale.5.dylib \
