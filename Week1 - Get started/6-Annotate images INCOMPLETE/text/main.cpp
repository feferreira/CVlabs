#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;


int main(){
    Mat image = imread("../input/boy.jpg", IMREAD_COLOR);
    
    Mat imageText = image.clone();
    string textStr = "I am studying";
    double fontScale = 1.5;
    int fontFace = FONT_HERSHEY_COMPLEX;
    Scalar fontColor = Scalar(250, 10, 10);
    int fontThickness = 2;

    putText(imageText, textStr, Point(20, 350), fontFace, fontScale, fontColor, fontThickness, LINE_AA);

    
    imwrite("../output/text.jpg", imageText);
    
    return 0;
}
