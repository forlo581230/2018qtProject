#include "addfacedialog.h"
#include "ui_addfacedialog.h"
#include <cassert>
AddFaceDialog::AddFaceDialog(QWidget *parent) : QMainWindow(parent),
                                                ui(new Ui::AddFaceDialog)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(ui->captureBtn, SIGNAL(clicked()), this, SLOT(openCamera()));
    connect(ui->submitBtn, SIGNAL(clicked()), this, SLOT(submit()));
    connect(ui->cancelBtn, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(timer, SIGNAL(timeout()), this, SLOT(startVideo()));


    faceRc = new FaceRecongnition();
}

AddFaceDialog::~AddFaceDialog()
{
    if (timer->isActive())
    {
        timer->stop();
    }
    delete ui;
}

void AddFaceDialog::openCamera()
{
    if (!video->isOpened())
    {
        return;
    }
    else
    {
        if (ui->inputNamelineEdit->text() != "")
        {
            timer->start(30);
            startVideo();
        }
        else
        {
            std::cout << "please input your name!" << std::endl;
        }
    }
}

void AddFaceDialog::openCameraTest(VideoCapture *input)
{
    video = input;
}

void AddFaceDialog::cancel()
{
    this->close();
}

void AddFaceDialog::submit()
{
    trainFace();
}

void AddFaceDialog::startVideo()
{
    cv::Mat videoFrame;
    *(video) >> videoFrame;
    if (videoFrame.empty())
    {
        return;
    }

    if (faceRc->find(videoFrame))
    {
        std::string folderName = ui->inputNamelineEdit->text().toUtf8().constData();
        faceRc->saveSample(folderName);
    }

    cv::resize(faceRc->videoFrame, videoFrame, cv::Size(341, 231), 0, 0, cv::INTER_CUBIC);
    QImage videoCapture = Mat2QImage(videoFrame);
    ui->addFaceLabel->setPixmap(QPixmap::fromImage(videoCapture));
}

void AddFaceDialog::trainFace()
{
    if (faceRc->training())
        this->close();
}

QImage AddFaceDialog::Mat2QImage(cv::Mat &temp)
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

cv::Mat AddFaceDialog::QImage2Mat(QImage const &src)
{
    cv::Mat tmp(src.height(), src.width(), CV_8UC3, (uchar *)src.bits(), src.bytesPerLine());
    cv::Mat result;
    cv::cvtColor(tmp, result, CV_BGR2RGB);
    return result;
}
