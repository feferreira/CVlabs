#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;




//We will use cv::resize function for resizing an image.
//Function Syntax

//void cv::resize (   InputArray  src,
//OutputArray     dst,
//Size    dsize,
//double  fx = 0,
//double  fy = 0,
//int     interpolation = INTER_LINEAR 
//)


int main(){
    Mat image = imread("../input/boy.jpg");
    
    int resizeDownWidth = 300;
    int resizeDownHeigth = 200;
    
    Mat resizedDown;
    resize(image, resizedDown, Size(resizeDownWidth, resizeDownHeigth), INTER_LINEAR);
    
    int resizeUpWidth = 600;
    int resizeUpHeight = 900;
    Mat resizedUp;
    resize(image, resizedUp, Size(resizeUpWidth, resizeUpHeight), INTER_LINEAR);
    
    imwrite("../output/resizedDown.png", resizedDown);
    imwrite("../output/resizedUp.png", resizedUp);
    
    //scaling factor
    
    //you have 400*600
    //you want 360*X
    //scale factor = 360/600 = 0.6
    
    //scale up image 1.5x
    double scaleUpX = 1.5;
    double scaleUpY = 1.5;
    
    //scale down single scale factor
    double scaledown = 0.6;
    
    Mat scaledUp, scaledDown;
    
    resize(image, scaledUp, Size(), scaleUpX, scaleUpY, INTER_LINEAR);
    resize(image, scaledDown, Size(), scaledown, scaledown, INTER_LINEAR);
    
    imwrite("../output/scaledDown.png", scaledDown);
    imwrite("../output/scaledUp.png", scaledUp);
    
        
    return 0;
}
