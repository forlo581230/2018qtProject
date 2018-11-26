#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    faceRc = new FaceRecongnition();
    timer = new QTimer(this);
    video = NULL;
    connect(ui->openCameraBtn, SIGNAL(clicked()), this, SLOT(openCamera()));
    connect(ui->exitBtn, SIGNAL(clicked()), this, SLOT(exit()));
    connect(ui->addFaceBtn, SIGNAL(clicked()), this, SLOT(openDialog()));
    connect(timer, SIGNAL(timeout()), this, SLOT(startVideo()));
    connect(ui->recognitionBtn, SIGNAL(clicked()), this, SLOT(doFaceRC()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openCamera()
{
    if (video == NULL){
        video = new VideoCapture(0);
    }


    if (!video->isOpened())
    {
        return;
    }
    else
    {
        timer->start(30);
        startVideo();
    }
}

void MainWindow::exit()
{
    this->close();
}

void MainWindow::openDialog()
{
    if (timer->isActive())
    {
        timer->stop();
    }
    dialog.openCameraTest(this->video);
    dialog.show();
}

void MainWindow::startVideo()
{

    *(video) >> videoFrame;
    if (videoFrame.empty())
    {
        return;
    }

    faceRc->find(videoFrame);
    Mat outputImg = faceRc->videoFrame;

    HOGDescriptor hog;
    hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
    vector<Rect> detected, detected_filtered;
    hog.detectMultiScale(videoFrame, detected, 0, Size(8, 8), Size(24, 24), 1.05, 2);
    size_t h, k;
    for (h = 0; h < detected.size(); h++)
    {
        Rect r = detected[h];
        for (k = 0; k < detected.size(); k++)
            if (k != h && (r & detected[k]) == r)
                break;
        if (k == detected.size())
            detected_filtered.push_back(r);
    }

    for (h = 0; h < detected_filtered.size(); h++)
    {
        Rect r = detected_filtered[h];
        r.x += cvRound(r.width * 0.1);
        r.width = cvRound(r.width * 0.8);
        r.y += cvRound(r.height * 0.07);
        r.height = cvRound(r.height * 0.8);
        rectangle(outputImg, r.tl(), r.br(), Scalar(0, 0, 255), 3);
    }

    cv::resize(videoFrame, videoFrame, cv::Size(351, 261), 0, 0, cv::INTER_CUBIC);
    cv::resize(outputImg, outputImg, cv::Size(351, 261), 0, 0, cv::INTER_CUBIC);
    QImage videoCapture = Mat2QImage(videoFrame);
    ui->inputLabel->setPixmap(QPixmap::fromImage(videoCapture));
    QImage processQimage = Mat2QImage(outputImg);
    ui->detectLabel->setPixmap(QPixmap::fromImage(processQimage));
    ui->facesLabel->setText("number of face: " + QString::number(faces.size()));
    ui->peopleLabel->setText("number of people: " + QString::number(detected_filtered.size()));
}

void MainWindow::doFaceRC()
{
    int predicted = faceRc->predict();
    ui->nameLabel->setText(QString::number(predicted));
}

QImage MainWindow::Mat2QImage(cv::Mat &temp)
{
    QImage dest;
    if (temp.channels() == 3)
    {
        cv::cvtColor(temp, temp, CV_BGR2RGB);
        dest = QImage((const uchar *)temp.data, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
    }
    else
    {
        dest = QImage((const uchar *)temp.data, temp.cols, temp.rows, temp.step, QImage::Format_Indexed8);
    }
    return dest;
}

cv::Mat MainWindow::QImage2Mat(QImage const &src)
{
    cv::Mat tmp(src.height(), src.width(), CV_8UC3, (uchar *)src.bits(), src.bytesPerLine());
    cv::Mat result;
    cv::cvtColor(tmp, result, CV_BGR2RGB);
    return result;
}
