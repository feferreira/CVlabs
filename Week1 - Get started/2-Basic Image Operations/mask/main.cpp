#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;


int main(){
    Mat image = imread("../input/boy.jpg");
    Mat mask1 = Mat::zeros(image.size(), image.type());
    imwrite("../output/mask1.png", mask1);
    
    mask1(Range(50,200), Range(170,320)).setTo(255);
    imwrite("../output/mask1.png", mask1);
    
    //create mask using pixel intensity or color
    
/*    
void cv::inRange    (   InputArray  src,
InputArray  lowerb,
InputArray  upperb,
OutputArray     dst 
)

Parameters
    src - first input array.
    lowerb - inclusive lower boundary array or a scalar.
    upperb - inclusive upper boundary array or a scalar.
    dst - output array of the same size as src and CV_8U type.
*/

    Mat mask2;
    inRange(image, Scalar(0,0,150), Scalar(100,100,255), mask2);
    imwrite("../output/mask2.png", mask2);
    
    return 0;
}
