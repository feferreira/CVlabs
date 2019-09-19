#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;


int main(){
    Mat image = imread("../input/boy.jpg");
    
    Mat copyRoi = image(Range(40,200),Range(180,320));
    
    int roiHeight = copyRoi.size().height;
    int roiWidth = copyRoi.size().width;
    
    copyRoi.copyTo(image(Range(40,40+roiHeight),Range(10,10+roiWidth)));
    copyRoi.copyTo(image(Range(40,40+roiHeight),Range(330,330+roiWidth)));    
    
    imwrite("../output/CopiedRegions.png", image);
    
    return 0;
}
