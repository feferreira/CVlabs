#ifndef QRDETECTOR_H
#define QRDETECTOR_H
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect.hpp>

using namespace cv;

class QrDetector
{
private:
    VideoCapture cap;
    Mat frame;
    Mat bbox, rectifiedImage;
    QRCodeDetector qrDecoder;
public:
    QrDetector();
    bool runDetector();
};

#endif // QRDETECTOR_H
