#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;


int main(){
    string imagePath = "../input/number_zero.jpg";
    Mat testImage = imread(imagePath, 1); //carrega uma imagem pb como colorida
    
    //access color pixel
    cout << testImage.at<Vec3b>(0,0) << '\n';
    
    //modify pixel
    //change 0,0 to yellow
    // 1,1 to cyan
    // 2,2 to magenta
    testImage.at<Vec3b>(0,0) = Vec3b(0,255,255);
    imwrite("../output/zero1.png", testImage);
    testImage.at<Vec3b>(1,1) = Vec3b(255,255,0);
    imwrite("../output/zero2.png", testImage);
    testImage.at<Vec3b>(2,2) = Vec3b(255,0,255);
    imwrite("../output/zero3.png", testImage);
    
    //modify region
    testImage(Range(0,3),Range(0,3)).setTo(Scalar(255,0,0));
    testImage(Range(3,6),Range(0,3)).setTo(Scalar(0,255,0));
    testImage(Range(6,9),Range(0,3)).setTo(Scalar(0,0,255));
    imwrite("../output/zeroModified.png", testImage);
    
    return 0;
}
