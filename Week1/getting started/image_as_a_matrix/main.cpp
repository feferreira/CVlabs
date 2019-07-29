#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

//lendo uma imagem
//Mat cv::imread (const string &filename, int flags = IMREAD_COLOR)
// argumento 1: path do arquivo
// argumento 2: flags para ler em um formato eespcifico
// IMREAD_GRAYSCALE, IMREAD_COLOR, IMREAD_UNCHANGED

//mostrando uma imagem
//void cv::imshow (const string & winname, inputArray mat)
// arg 1: nome da janela
// arg 2: imagem a ser mostrada
// funções úteis:
// namedWindow (const string & winname, int flags = WINDOWS_AUTOSIZE)
// waitKey (int delay_ms = 0) 
// destroyWindow (const string &winname)
// destroyAllWindows

//gravando imagem
// bool cv::imwrite (const string &fileName, inputArray img, const std::vector< int > &  params = std::vector< int >())
// param1: nome do arquivo
// param2: array da imagem
// param3: flags adicionais

//depth: quantas cores a imagem pode exibir
string type2str(int type) {
    string r;
    
    uchar depth = type & CV_MAT_DEPTH_MASK;
    uchar chans = 1 + (type >> CV_CN_SHIFT);
    
    switch(depth){
        case CV_8U: r = "8U"; break;
        case CV_8S: r = "8S"; break;
        case CV_16U: r = "16U"; break;
        case CV_16S: r = "16S"; break;
        case CV_32S: r = "32S"; break;
        case CV_32F: r = "32F"; break;
        case CV_64F: r = "64F"; break;
        default:     r = "User";break;
    }
    
    r += "C";
    r += (chans+'0');
    return r;
}

int main(){
    string imagePath = "number_zero.jpg";
    Mat testImage = imread(imagePath, 0);
    cout << testImage << endl;
    cout << "Image dimesions " << testImage.size() << '\n';
    cout << "Data type: " << type2str(testImage.type()) << '\n';
    
    //acessando pixels
    cout << "First Pixel Value: "<< static_cast<int>(testImage.at<uchar>(0,0)) << '\n';
    
    //modificando pixels
    testImage.at<uchar>(0,0) = 200;
    cout << "Modified Pixel Value: "<< static_cast<int>(testImage.at<uchar>(0,0)) << '\n';
    cout << testImage << '\n';
    
    //acessando uma região
    Mat testRoi = testImage(Range(0,2), Range(0,4));
    cout << "Selected Region:\n" << testRoi << '\n';
    
    //Alterando uma região
    testImage(Range(0,2), Range(0,4)).setTo(111);
    cout << "Modified matrix\n" << testImage << '\n';
    
    //exibindo imagens
    imshow("hello world", testImage);
    waitKey(0); //espera tecla ser pressionada
    
    //escrevendo imagem
    imwrite("result.jpg", testImage);
    
    return 0;
}
