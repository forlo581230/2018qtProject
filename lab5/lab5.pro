#-------------------------------------------------
#
# Project created by QtCreator 2018-11-16T11:08:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab5
TEMPLATE = app

INCLUDEPATH += /usr/local/include \


LIBS += /usr/local/lib/libopencv_nonfree.so \
        /usr/local/lib/libopencv_imgproc.so \
        /usr/local/lib/libopencv_highgui.so \
        /usr/local/lib/libopencv_core.so \
        /usr/local/lib/libopencv_calib3d.so \
        /usr/local/lib/libopencv_ml.so \
        /usr/local/lib/libopencv_contrib.so \
        /usr/local/lib/libopencv_photo.so \
        /usr/local/lib/libopencv_legacy.so \
        /usr/local/lib/libopencv_stitching.so \
        /usr/local/lib/libopencv_features2d.so \
        /usr/local/lib/libopencv_flann.so \
        /usr/local/lib/libopencv_objdetect.so \
        /usr/local/lib/libopencv_gpu.so \
        /usr/local/lib/libopencv_video.so \
        /usr/local/lib/libopencv_videostab.so \
        /usr/local/lib/libopencv_superres.so \
        /usr/lib/x86_64-linux-gnu/libv4l/v4l1compat.so

SOURCES += main.cpp\
        mainwindow.cpp \
    addfacedialog.cpp \
    facerecongnition.cpp

HEADERS  += mainwindow.h \
    addfacedialog.h \
    facerecongnition.h

FORMS    += mainwindow.ui \
    addfacedialog.ui
