#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat image{imread("../input/erosion_example.jpg",IMREAD_GRAYSCALE)};

    //method 1: big kernel
    int kernelSize{7};

    Mat kernel1 = getStructuringElement(MORPH_ELLIPSE,Size(kernelSize, kernelSize)) ;
    //show kernel
    imshow("Kernel1", 255*kernel1);
    waitKey(0);
    destroyWindow("Kernel1");

    // dilate and show image
    Mat imageEroded;
    erode(image,imageEroded,kernel1);
    imshow("Image Eroded", imageEroded);
    waitKey(0);
    destroyWindow("Image Eroded");

    //method 2: small kernel and multiple iteraction
    kernelSize = 3;
    Mat kernel2{getStructuringElement(MORPH_ELLIPSE, Size(kernelSize, kernelSize))};
    Mat imageEroded2, imageEroded3;

    // dilate 1x
    erode(image, imageEroded2,kernel2,Point(-1,-1),1);
    imshow("Eroded 1x",imageEroded2);
    waitKey(0);
    destroyWindow("Eroded 1x");

    // dilate 2x
    erode(image, imageEroded3, kernel2, Point(-1,-1),2);
    imshow("Eroded 2x", imageEroded3);
    waitKey(0);
    destroyWindow("Eroded 2x");

    return 0;
}
