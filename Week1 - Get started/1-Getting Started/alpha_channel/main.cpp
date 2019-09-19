#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;


int main(){
    string imagePath = "../input/panther.png";
    
    Mat imgPng = imread(imagePath, -1); //le a imagem como ela é
    cout << "image Size: " << imgPng.size() << "\nimage channel: " << imgPng.channels() << '\n';
    
    Mat imgBGR;
    Mat imgPngChannels[4];
    split(imgPng, imgPngChannels);
    
    merge(imgPngChannels, 3, imgBGR);
    
    Mat imgPngMask = imgPngChannels[3];
    
    imwrite("../output/colorChannels.png", imgBGR);
    imwrite("../output/alphaChannel.png", imgPngMask);
    
    return 0;
}
