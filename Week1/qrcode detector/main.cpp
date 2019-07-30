#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <string>


using namespace std;
using namespace cv;


int main(){
    string imgPath = "../input/IDCard-Satya.png";
    
    Mat img = imread(imgPath);
    
    cout << img.size().height << " " << img.size().width;
    
    Mat bbox, rectifiedImage;

    // Create a QRCodeDetector Object
    // Variable name should be qrDecoder
    ///
    QRCodeDetector qrDecoder;
    ///



// Detect QR Code in the Image
// Output should be stored in opencvData
///

    string opencvData = qrDecoder.detectAndDecode(img, bbox, rectifiedImage);
///

// Check if a QR Code has been detected
    if(opencvData.length()>0)
        cout << "QR Code Detected" << endl;
    else
        cout << "QR Code NOT Detected" << endl;
    
    int n = bbox.rows;
    
  for(int i = 0 ; i < n ; i++)
  {
    line(img, Point2i(bbox.at<float>(i,0),bbox.at<float>(i,1)), Point2i(bbox.at<float>((i+1) % n,0), bbox.at<float>((i+1) % n,1)), Scalar(255,0,0), 3);
  }
    imshow("teste", img);
    waitKey(-1);
    return 0;
}
