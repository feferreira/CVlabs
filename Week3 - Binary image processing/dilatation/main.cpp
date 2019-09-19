#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// two methods
// single big kernel and small kernel with iterations

int main()
{
    Mat image{imread("../input/dilation_example.jpg",IMREAD_GRAYSCALE)};

    //method 1: big kernel
    int kernelSize{7};

    Mat kernel1 = getStructuringElement(MORPH_ELLIPSE,Size(kernelSize, kernelSize)) ;
    //show kernel
    imshow("Kernel1", 255*kernel1);
    waitKey(0);
    destroyWindow("Kernel1");

    // dilate and show image
    Mat imageDilated;
    dilate(image,imageDilated,kernel1);
    imshow("Image Dilated", imageDilated);
    waitKey(0);
    destroyWindow("Image Dilated");

    //method 2: small kernel and multiple iteraction
    kernelSize = 3;
    Mat kernel2{getStructuringElement(MORPH_ELLIPSE, Size(kernelSize, kernelSize))};
    Mat imageDilated2, imageDilated3;

    // dilate 1x
    dilate(image, imageDilated2,kernel2,Point(-1,-1),1);
    imshow("Dilate 1x",imageDilated2);
    waitKey(0);
    destroyWindow("Dilate 1x");

    // dilate 2x
    dilate(image, imageDilated3, kernel2, Point(-1,-1),2);
    imshow("dilate 2x", imageDilated3);
    waitKey(0);
    destroyWindow("Dilate 2x");

    return 0;
}
