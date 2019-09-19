#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;


int main(){
    Mat image = imread("../input/boy.jpg");
    
    Mat crop = image(Range(40,200),Range(170,320));
    imwrite("../output/crop.png", crop);
    
    return 0;
}
