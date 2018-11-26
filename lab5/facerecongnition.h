#ifndef FACERECONGNITION_H
#define FACERECONGNITION_H

#include <string>
#include <sys/stat.h>
#include <sys/dir.h>
#include <stdlib.h>
#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/contrib/contrib.hpp>
using namespace cv;

class FaceRecongnition
{
  public:
    FaceRecongnition();
    bool find(Mat);
    int predict();
    bool saveSample(std::string);
    bool training();
    cv::Mat videoFrame;

  private:
    cv::CascadeClassifier _faceCascade;
    cv::CascadeClassifier _eyesCascade;
    std::vector<cv::Rect> faces;
    std::vector<cv::Rect> eyes;
    cv::Mat faceRoi;
    int sampleCnt;

    Ptr<FaceRecognizer> model = createEigenFaceRecognizer();
    std::vector<char *> getFolders(char *dir, int depth);
    std::vector<char *> getFiles(char *dir, int depth);
};

#endif // FACERECONGNITION_H
