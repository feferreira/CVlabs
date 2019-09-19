

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
    //cout << demoImage << '\n';

    //add some white blobs
    demoImage.at<uchar>(0,1) = 1;
    demoImage.at<uchar>(9,0) = 1;
    demoImage.at<uchar>(8,9) = 1;
    demoImage.at<uchar>(2,2) = 1;
    demoImage(Range(5,8),Range(5,9)).setTo(1);

    //show image
    imshow("image", 512*demoImage);
    waitKey(0);
    destroyWindow("image");

    //create a 3x3 ellipse structure
    Mat element = getStructuringElement(MORPH_CROSS,Size(3,3));
    int ksize = element.size().height; // guarda o tamanho do kernel
    int height = demoImage.size().height;
    int width = demoImage.size().width;

    //demoImage é a imagem original
    //element é a estrutura
    //paddedDemo é a imagem original, com borda

    //dilatation from scratch, method 2

    int border = ksize/2;
    Mat paddedDemoImage = Mat::zeros(Size(height + border*2, width + border*2),CV_8UC1);
    copyMakeBorder(demoImage,paddedDemoImage,border,border,border,border,BORDER_CONSTANT,0);

    Mat paddedDilatedImage = paddedDemoImage.clone();
    Mat mask;
    Mat resizedFrame;
    Mat bitAnd;
    double minVal, maxVal;

    // Create a VideoWriter object
    ///
    VideoWriter outavi("dilationScratch.avi",cv::VideoWriter::fourcc('M','J','P','G'),10, Size(50,50));
    ///

    for (int h_i = border; h_i < height + border; h_i++){
        for (int w_i = border; w_i < width + border; w_i++){
            bitwise_and(paddedDemoImage(Range(h_i-border,h_i+border+1),
                                         Range(w_i-border,w_i+border+1)), element, bitAnd);
            if(bitAnd.at<uchar>(0,1) || bitAnd.at<uchar>(1,0) || bitAnd.at<uchar>(1,2) || bitAnd.at<uchar>(2,1))
                demoImage.at<uchar>(h_i-border, w_i-border) = 1;

            resize(demoImage,resizedFrame,Size(50,50),INTER_AREA);

            Mat color;
            cvtColor(resizedFrame,color,COLOR_GRAY2BGR);

            imshow("result", resizedFrame*255);
            outavi.write(color*255);
            waitKey(100);
        }
    }

    // Release the VideoWriter object
    ///
    outavi.release();

    return 0;
}
