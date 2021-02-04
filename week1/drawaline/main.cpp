#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(){
    const char * imagePath = "../images/billie.jpg";
    cv::Mat image = cv::imread(imagePath, cv::IMREAD_COLOR);
    cv::line(image,cv::Point(50,50),cv::Point(100,100),cv::Scalar(0,0,255),5);
    cv::circle(image,Point(100,100),50,Scalar(255,0,0),3);
    cv::ellipse(image,Point(150,125),Size(100,50),0,0,360,Scalar(0,255,0),3);
    cv::rectangle(image,Point(200,250),Point(29,50),Scalar(255,255,0),3);
    cv::putText(image,"Texto",Point(200,0),FONT_HERSHEY_COMPLEX,1.5,Scalar(255,0,255),3);
    cv::imshow("line",image);
    cv::waitKey(0);
    return 0;
}
