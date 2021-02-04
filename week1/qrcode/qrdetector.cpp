#include"qrdetector.h"
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <string>

QrDetector::QrDetector()
{
    if(cap.open(0)){
        std::cout << "Camera Open!";
    }
    else {
        std::cout << "Camera don't open!";
    }
    if(!cap.isOpened()){
        std::cout << "Unable to detect webcam\n";
        return;
    }
    else{
        cap.set(3,640);
        cap.set(4,480);
    }
}

bool QrDetector::runDetector()
{
        cap >> frame;

        std::string decodifiedStr = qrDecoder.detectAndDecode(frame, bbox, rectifiedImage);
        /*if(!decodifiedStr.empty()){
            std::cout << decodifiedStr;
            std::cout << bbox.at<int>(0,0) << bbox.at<int>(bbox.rows, bbox.cols);
            rectangle(frame, Point2i(bbox.at<int>(0,0)),Point2i(bbox.at<int>(bbox.rows, bbox.cols)),Scalar(0,0,255),10);
            imshow("frame", frame);
            cv::waitKey(0);
            return true;
        }
        else{
            return false;
        }*/
        return false;
}

