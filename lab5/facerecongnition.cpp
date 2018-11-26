#include "facerecongnition.h"

FaceRecongnition::FaceRecongnition()
{
    //_faceCascade.load("./haarcascades/haarcascade_frontalface_alt_tree.xml");
    assert(_faceCascade.load("haarcascades/haarcascade_frontalface_default.xml") == true);
    assert(_eyesCascade.load("haarcascades/haarcascade_eye_tree_eyeglasses.xml") == true);
    sampleCnt = 0;

    model->load("model.xml");
}

/*
videoFrame
*/
bool FaceRecongnition::find(Mat mat)
{
    videoFrame = mat.clone();
    bool beFound = false;

    Mat frameGray;
    cv::cvtColor(videoFrame, frameGray, CV_BGR2GRAY);
    _faceCascade.detectMultiScale(frameGray, faces, 1.1, 3, 0 | CV_HAAR_SCALE_IMAGE, cv::Size(32, 32));

    for (size_t i = 0; i < faces.size(); i++)
    {
        faceRoi = videoFrame.clone()(faces[i]);
        _eyesCascade.detectMultiScale(faceRoi, eyes, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, cv::Size(8, 8));
        for (size_t j = 0; j < eyes.size(); j++)
        {
            cv::Point center(faces[i].x + eyes[j].x + eyes[j].width * 0.5, faces[i].y + eyes[j].y + eyes[j].height * 0.5);
            int radius = round((eyes[j].width + eyes[j].height) * 0.25);
            cv::circle(videoFrame, center, radius, cv::Scalar(255, 0, 0), 4, 8, 0);
        }
        //when eye be found
        if (eyes.size() == 2)
        {
            beFound = true;
            cv::rectangle(videoFrame, faces[i], cv::Scalar(0, 128, 255), 3);
        }
    }

    return beFound;
}

bool FaceRecongnition::saveSample(std::string folderName)
{
    if (!(eyes.size() == 2))
    {
        return false;
    }

    // std::string folder = ui->inputNamelineEdit->text().toUtf8().constData();
    const int dir_err = mkdir(folderName.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    if (-1 == dir_err)
    {
    }

    std::stringstream ss;
    ss << sampleCnt;
    bool isSave = imwrite("./" + folderName + "/" + ss.str() + ".jpg", faceRoi);
    sampleCnt++;

    return isSave;
}

int FaceRecongnition::predict()
{
    if (faceRoi.empty())
    {
        return -999;
    }
    Mat grayImg;
    cv::cvtColor(faceRoi, grayImg, CV_BGR2GRAY);
    ////ŽúžÕ
    ////Š³°ÑŒÆ¡C
    ////predicted = model->predict(img, label, conf)
    ////µL°ÑŒÆ¡C
    ///
    ///
    cv::resize(grayImg, grayImg, cv::Size(100, 100), 0, 0, cv::INTER_CUBIC);
    return model->predict(grayImg);
}

bool FaceRecongnition::training()
{
    std::vector<char *> folders = getFolders("./", 0);

    vector<Mat> images;
    vector<int> labels;
    // images for first person
    std::cout << folders.size() << std::endl;
    for (int i = 0; i < folders.size(); i++)
    {

        std::cout << folders.size() << " dir: " << folders[i] << std::endl;
        std::vector<char *> files = getFiles(folders[i], 0);
        std::cout << files.size() << " dir: " << folders[i] << std::endl;
        for (int j = 0; j < files.size(); j++)
        {

            string path = std::string(folders[i]) + "/" + std::string(files[j]);
            std::cout << path << std::endl;
            Mat img = imread(path, CV_LOAD_IMAGE_GRAYSCALE);
            cv::resize(img, img, cv::Size(100, 100), 0, 0, cv::INTER_CUBIC);
            images.push_back(img);
            labels.push_back(i);
        }
        files.clear();
    }

    //opencvŠ³Ž£šÑ€TºØ€èªk¡C
    //Š³ªùÂe­È
    //Ptr<FaceRecognizer> model = createEigenFaceRecognizer(component, threshold);
    //µLªùÂe­È
    Ptr<FaceRecognizer> model = createEigenFaceRecognizer();
    //°Vœm
    model->train(images, labels);
    //ÀxŠsmodel
    model->save("model.xml");
    //Mat img = imread("person1/2.jpg", CV_LOAD_IMAGE_GRAYSCALE);
    ////ŽúžÕ
    ////Š³°ÑŒÆ¡C
    ////predicted = model->predict(img, label, conf)
    ////µL°ÑŒÆ¡C
    //int predicted = model->predict(img);
}

std::vector<char *> FaceRecongnition::getFolders(char *dir, int depth)
{
    std::vector<char *> folders;
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    if ((dp = opendir(dir)) == NULL)
    {
        fprintf(stderr, "cannot open directory: %s\n", dir);
        return folders;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        lstat(entry->d_name, &statbuf);
        if (S_ISDIR(statbuf.st_mode))
        {
            /* Found a directory, but ignore . and .. */
            if (strcmp(".", entry->d_name) == 0 ||
                strcmp("..", entry->d_name) == 0)
                continue;
            printf("%*s%s/\n", depth, "", entry->d_name);
            //std::cout << entry->d_name << std::endl;
            char *strTmp = new char();
            strTmp = strcpy(strTmp, entry->d_name);
            printf("%*s%s/\n", depth, "", strTmp);
            folders.push_back(strTmp);
            /* Recurse at a new indent level */
            //            printdir(entry->d_name,depth+4);
        }
        //        else printf("%*s%s\n",depth,"",entry->d_name);
    }
    closedir(dp);

    for (int i = 0; i < folders.size(); i++)
    {
        if (strcmp(folders[i], "haarcascades") == 0)
            folders.erase(folders.begin() + i);
    }

    return folders;
}

std::vector<char *> FaceRecongnition::getFiles(char *dir, int depth)
{
    std::vector<char *> files;
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;
    if ((dp = opendir(dir)) == NULL)
    {
        fprintf(stderr, "cannot open directory: %s\n", dir);
        return files;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        lstat(entry->d_name, &statbuf);
        if (S_ISDIR(statbuf.st_mode))
        {
            /* Found a directory, but ignore . and .. */
            if (strcmp(".", entry->d_name) == 0 ||
                strcmp("..", entry->d_name) == 0)
                continue;
            //            printf("%*s%s/\n",depth,"",entry->d_name);

            /* Recurse at a new indent level */
            //            printdir(entry->d_name,depth+4);
        }
        else
        {
            //            printf("%*s%s\n",depth,"",entry->d_name);
        }
        char *strTmp = new char();
        strcpy(strTmp, entry->d_name);
        files.push_back(strTmp);
    }
    closedir(dp);

    return files;
}
