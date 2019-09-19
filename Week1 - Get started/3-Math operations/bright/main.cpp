#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;


int main(){
    Mat image = imread("../input/boy.jpg");
    int brightnessOffset = 50;
    
    Mat brightHigh = image;
    Mat brightHighChannels[3];
    split(brightHigh, brightHighChannels);
    
    for(int i=0; i < 3; i++){
        add(brightHighChannels[i],brightnessOffset,brightHighChannels[i]);
    }
    
    merge(brightHighChannels,3,brightHigh);
    imwrite("../output/brightHigh.png", brightHigh);
    
    return 0;
}
