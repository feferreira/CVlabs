#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

//function to implement threshold manually
void thresholdingUsingForLoop(Mat src, Mat dst, int thresh, int maxValue){
    int height = src.size().height;
    int width = src.size().width;
    // Loop over rows
    for (int i=0; i < height; i++){
        // Loop over columns
        for (int j=0; j < width; j++){
            if (src.at<uchar>(i,j) > thresh)
                dst.at<uchar>(i,j) = static_cast<uchar>(maxValue);
            else
                dst.at<uchar>(i,j) = 0;
        }
    }
}

int main()
{
    Mat image{imread("../input/threshold.png", IMREAD_GRAYSCALE)};
    int thresh{100};
    int maxValue{255};
    imshow("image", image);
    waitKey(0);
    destroyWindow("image");

    //Thresholding using for loop
    Mat dst = image.clone();
    thresholdingUsingForLoop(image,dst,thresh,maxValue);
    imshow("manual", dst);
    waitKey(0);
    destroyWindow("manual");

    //Thresholding using cv
    threshold(image,dst,thresh,maxValue,THRESH_BINARY);
    imshow("THRESH_BINARY", dst);
    waitKey(0);
    destroyWindow("THRESH_BINARY");

    thresh = 100;
    maxValue = 150;
    threshold(image,dst,thresh,maxValue,THRESH_BINARY_INV);
    imshow("THRESH_BINARY_INV", dst);
    waitKey(0);
    destroyWindow("THRESH_BINARY_INV");

    threshold(image,dst,thresh,maxValue,THRESH_TRUNC);
    imshow("THRESH_TRUNC", dst);
    waitKey(0);
    destroyWindow("THRESH_TRUNC");

    threshold(image,dst,thresh,maxValue,THRESH_TOZERO);
    imshow("THRESH_TOZERO", dst);
    waitKey(0);
    destroyWindow("THRESH_TOZERO");

    threshold(image,dst,thresh,maxValue,THRESH_TOZERO_INV);
    imshow("THRESH_TOZERO_INV", dst);
    waitKey(0);
    destroyWindow("THRESH_TOZERO_INV");
    return 0;
}
