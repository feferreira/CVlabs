#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

//void cv::line   (InputOutputArray   img, < onde vai desenhar a linha
//Point   pt1, < primeiro ponto do segmento
//Point   pt2, < segundo ponto do segmento
//const Scalar &  color, cor da linha
//int     thickness = 1, < opcional, espessura da linha
//int     lineType = LINE_8, < tipo da linha
//int     shift = 0 
//)

//

int main(){
    Mat image = imread("../input/boy.jpg", IMREAD_COLOR);
    
    Mat imageLine = image.clone();
    
    line(imageLine, Point(200,80), Point(280,80), Scalar(0,255,0), 3, LINE_AA);
    
    imwrite("../output/line.jpg", imageLine);
    
    return 0;
}
