#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;


int main(){
    Mat image = imread("../input/boy.jpg");
    
    double contrastPercentage = 30.0;
    
    Mat contrastHigh = image;
    
    contrastHigh.convertTo(contrastHigh, CV_64F);
    contrastHigh = contrastHigh * (1 + contrastPercentage/100.0);
    imwrite("../output/highContrast.png", contrastHigh);
    
    return 0;
}
