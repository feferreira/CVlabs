#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;


int main(){
    Mat image = imread("../input/boy.jpg");
    
    double scalingFactor = 1/255.0;
    double shift = 0;
    
    //reduz o range de 0-255 para 0-1
    image.convertTo(image, CV_32FC3, scalingFactor, shift);
    image.convertTo(image, CV_8UC3, 1.0/scalingFactor, shift);
    
    return 0;
}
