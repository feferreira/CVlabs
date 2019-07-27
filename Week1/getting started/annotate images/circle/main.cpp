#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;
/*
void cv::circle (   InputOutputArray    img, < imagem
Point   center, < centro do circulo
int     radius, < raio
const Scalar &  color, < cor
int     thickness = 1, < espessura da linha
int     lineType = LINE_8, < tipo da linha
int     shift = 0 
)

*/

int main(){
    Mat image = imread("../input/boy.jpg", IMREAD_COLOR);
    
    Mat imageCircle = image.clone();
    
    circle(imageCircle, Point(250,125), 100, Scalar(0,0,255), 5, LINE_AA);
    
    imwrite("../output/circle.jpg", imageCircle);
    
    Mat imageFilledCircle = image.clone();
    
    circle(imageFilledCircle, Point(250,125), 100, Scalar(0,0,255), -1, LINE_AA);
    imwrite("../output/circleFilled.jpg", imageFilledCircle);
    
    return 0;
}
