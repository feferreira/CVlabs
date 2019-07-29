#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;


int main(){
    string imagePath = "../input/boy.jpg";
    Mat image = imread(imagePath);
    
    //cria copia da imagem
    Mat imageCopy = image.clone();
    
    //cria matriz vazia de 100x200
    
    Mat emptyMatrix = Mat(100,200,CV_8UC3,Scalar(0,0,0));
    imwrite("../output/emptyMatrix.png",emptyMatrix);
    
    //preenche de branco
    emptyMatrix.setTo(Scalar(255,255,255));
    imwrite("../output/emptyMatrixWhite.png",emptyMatrix);
    
    //cria com mesmo tipo e tamanho que a original
    Mat emptyOriginal(emptyMatrix.size(),emptyMatrix.type(),Scalar(100,100,100));
    imwrite("../output/emptyOriginal.png",emptyOriginal);
    
    
    
    return 0;
}
