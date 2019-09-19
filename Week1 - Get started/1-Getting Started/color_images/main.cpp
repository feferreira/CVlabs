#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

//uma imagem colorida consiste em multiplos channels, cada channel é uma imagem grayscale
//The combination of intensity values of the three channels gives the color that is displayed on the screen.
// use split para dvidir os canais da imagem

int main(){
    string imagePath = "../input/musk.jpg";
    
    Mat img = imread(imagePath);
    
    cout << "image size: " << img.size() << '\n';
    
    Mat imgChannels[3];
    split(img, imgChannels);
    imwrite("../output/imgBlue.jpg", imgChannels[0]);
    imwrite("../output/imgGreen.jpg", imgChannels[1]);
    imwrite("../output/imgRed.jpg", imgChannels[2]);
    
    
    return 0;
}
