#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;
/*
void cv::ellipse    (   InputOutputArray    img, < imagem
Point   center, < centro do elipse
Size    axes, < metade do tamanho do elipse
double  angle, < rotação do elipse
double  startAngle, <angulo inicial
double  endAngle, < angulo final
const Scalar &  color, < cor
int     thickness = 1,
int     lineType = LINE_8,
int     shift = 0 
)
*/

int main(){
    Mat image = imread("../input/boy.jpg", IMREAD_COLOR);
    
    Mat imageEllipse = image.clone();
    
    ellipse(imageEllipse, Point(250,125), Point(100,50), 0,0,360, Scalar(255,0,0), 3, LINE_AA);
    
    ellipse(imageEllipse, Point(250,125), Point(100,50), 90, 0, 360, Scalar(0, 0, 255), 3, LINE_AA);
    
    imwrite("../output/ellipse.jpg", imageEllipse);
    
    Mat imageFilledCircle = image.clone();
    
    circle(imageFilledCircle, Point(250,125), 100, Scalar(0,0,255), -1, LINE_AA);
    imwrite("../output/circleFilled.jpg", imageFilledCircle);
    
    return 0;
}
