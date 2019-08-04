#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

Point topLeft, bottomRight;
Mat image, original;

void drawRectangle(int action, int x, int y, int flags, void *userdata){
    if( action == EVENT_LBUTTONDOWN )
    {
        //store first edge
        topLeft = Point(x,y);
        //clear annotation
        image = original.clone();
    }
    else if( action == EVENT_LBUTTONUP)
    {
        //store opposite edge and show
        bottomRight = Point(x,y);
        rectangle(image, topLeft, bottomRight, Scalar(255,255,0), 2);
        //crop and save image
        Mat cropped = image(Rect(topLeft,bottomRight));
        imwrite("../output/cropped.png", cropped);
    }
}

int main(){
    // text to display
    string text = "Select top left corner, and drag";
    //read image file
    image = imread("../input/sample.jpg");
    //create window
    namedWindow("Window");
    //set mouse event callback
    setMouseCallback("Window", drawRectangle);
    //write text on image
    putText(image, text, Point(0,20), FONT_HERSHEY_PLAIN, 1.5, Scalar(255,255,255), 2);
    //create a backup for clearing
    original = image.clone();
    //create var to store key pressed
    int k=0;
    //loop until escape
    while(k != 27){
        imshow("Window", image);
        k = waitKey(200);
    }
    return 0;
}
