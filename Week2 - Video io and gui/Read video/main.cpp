#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;


int main(){
    VideoCapture cap("../input/chaplin.mp4");
    
    if(!cap.isOpened()){
        cout << "Error opening video stream" << endl;
    }
    
    while(cap.isOpened()){
        Mat frame;
        
        cap >> frame;
        
        if(frame.empty())
            break;
        
        imshow("video",frame);
        waitKey(25);
    }
    
    return 0;
}
