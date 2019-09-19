#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;


int main(){
    Mat image = imread("../input/boy.jpg", IMREAD_COLOR);
    
    Mat imageRectangle = image.clone();

    rectangle(imageRectangle, Point(170, 50), Point(300, 200),
              Scalar(255, 0, 255), 5, LINE_8);
    
    imwrite("../output/rectangle.jpg", imageRectangle);
    
    return 0;
}
