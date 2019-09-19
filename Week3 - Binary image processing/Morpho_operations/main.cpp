#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    Mat demoImage = Mat::zeros(Size(10,10),CV_8U);
    cout << demoImage << '\n';

    //add some white blobs
    demoImage.at<uchar>(0,1) = 1;
    demoImage.at<uchar>(9,0) = 1;
    demoImage.at<uchar>(8,9) = 1;
    demoImage.at<uchar>(2,2) = 1;
    demoImage(Range(5,8),Range(5,8)).setTo(1);

    //show image
    imshow("image", 255*demoImage);
    waitKey(0);
    destroyWindow("image");

    //create a 3x3 ellipse structure
    Mat element = getStructuringElement(MORPH_CROSS,Size(3,3));
    int ksize = element.size().height; // guarda o tamanho do kernel
    int height = demoImage.size().height;
    int width = demoImage.size().width;

    //dilatation from scratch, method 1

    int border = ksize/2;

    Mat paddedDemoImage = Mat::zeros(Size(height + border*2, width + border * 2), CV_8UC1);
    copyMakeBorder(demoImage,paddedDemoImage,border,border,border,border,BORDER_CONSTANT,0);

    Mat bitOR;

    for (int h_i=border; h_i < height + border; h_i++){
        for (int w_i=border; w_i < width + border; w_i++){
            if (demoImage.at<uchar>(h_i-border, w_i-border)){
                cout << "White Pixel Found @ " << h_i << "," << w_i << endl;
                cout << paddedDemoImage(Range(h_i-border,h_i+border+1),
                               Range(w_i-border,w_i+border+1)) << endl;
                cout << element << endl;
                bitwise_or(paddedDemoImage(Range(h_i-border,h_i+border+1),
                               Range(w_i-border,w_i+border+1)),element,bitOR);
                cout << bitOR << endl;
                cout << paddedDemoImage(Range(h_i-border,h_i+border+1),
                               Range(w_i-border,w_i+border+1)) << endl;
                bitOR.copyTo(paddedDemoImage(Range(h_i-border,h_i+border+1),
                               Range(w_i-border,w_i+border+1)));
                cout << paddedDemoImage << endl;
            }
        }
    }
    Mat dilatedImage = paddedDemoImage(Range(border,border+height),Range(border,border+width));
    imshow("result1", dilatedImage*255);
    waitKey(0);
    destroyWindow("result1");

    return 0;
}
