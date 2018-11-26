#ifndef ADDFACEDIALOG_H
#define ADDFACEDIALOG_H
#include <string.h>
#include <QMainWindow>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <sys/dir.h>
#include <QTimer>
#include "facerecongnition.h"

namespace Ui {
class AddFaceDialog;
}

class AddFaceDialog : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddFaceDialog(QWidget *parent = 0);
    ~AddFaceDialog();
    void openCameraTest(VideoCapture *);

private:
    Ui::AddFaceDialog *ui;
    QImage Mat2QImage(cv::Mat & src);
    cv::Mat QImage2Mat(QImage const& src);
    cv::Mat _mat;
    QTimer *timer;

    VideoCapture *video;
    void trainFace();
    FaceRecongnition *faceRc;

private slots:
    void openCamera();
    void cancel();
    void submit();
    void startVideo();

};

#endif // ADDFACEDIALOG_H

