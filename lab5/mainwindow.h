#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QDebug>
#include <QImage>
#include <QPixmap>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <ctime>
#include <sstream>
#include <QTimer>
#include <vector>
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/nonfree/nonfree.hpp"
#include "addfacedialog.h"
#include "facerecongnition.h"

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTimer *timer;

  private:
    Ui::MainWindow *ui;
    cv::Mat _mat;
    QImage Mat2QImage(cv::Mat &src);
    cv::Mat QImage2Mat(QImage const &src);

    cv::VideoCapture *video;
    AddFaceDialog dialog;
    cv::Mat videoFrame_src;
    cv::Mat videoFrame;
    cv::CascadeClassifier _faceCascade;
    cv::CascadeClassifier _eyesCascade;
    cv::CascadeClassifier _peopleCascade;
    std::vector<cv::Rect> faces;
    cv::Mat frameGray;

    FaceRecongnition *faceRc;

  private slots:
    void doFaceRC();
    void openDialog();
    void openCamera();
    void exit();
    void startVideo();
};

#endif // MAINWINDOW_H
