#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

int main(){
    //set path's
    const char * sunglassPath = "../images/sunglasses.png";
    const char * chicoPath = "../images/chico.jpg";
    //open image files
    cv::Mat sunglasses = cv::imread(sunglassPath, cv::IMREAD_UNCHANGED);
    cv::Mat chico = cv::imread(chicoPath);
        
    std::cout << "size of sunglasses: " << sunglasses.size() << '\n';
    std::cout << "size of chico: " << chico.size() << '\n';
    std::cout << "channels of sunglasses: " << sunglasses.channels() << '\n';
    std::cout << "channels of chico: " << chico.channels() << '\n';
    
    //resize sunglasses to fit in images
    cv::resize(sunglasses, sunglasses, cv::Size(100,80));
    int glassHeight = sunglasses.size().height;
    int glassWidth = sunglasses.size().width;
    
    //separate channels of sunglasses
    cv::Mat glassRgbaChannels[4];
    cv::split(sunglasses, glassRgbaChannels);
    
    //separate glass mask from glassBgr
    cv::Mat glassRgbChannels[3];
    for(int i = 0; i < 3; i++){
        glassRgbChannels[i] = glassRgbaChannels[i];
    }
    
    //create a bgr image without alpha channel
    cv::Mat glassBgr;
    cv::merge(glassRgbChannels,3,glassBgr);
    cv::Mat glassBgr2 = glassBgr;
    //create a 3 channel mask with the alphaChannel
    cv::Mat glassMask1 = glassRgbaChannels[3];
    cv::Mat glassMaskChannels[3] = {glassMask1, glassMask1, glassMask1};
    cv::Mat glassMask;
    cv::merge(glassMaskChannels,3,glassMask);
    cv::Mat glassMask2 = glassMask.clone(); 
    //change range from 0 to 1 
    glassMask = glassMask/255;

    //create a clone of image and get the eye region
    cv::Mat chicoGlasses = chico.clone();
    int startEyeR = 180;
    int startEyeC = 85;
    cv::Mat chicoEyeRoi = chicoGlasses(cv::Range(startEyeR,startEyeR+glassHeight),
            cv::Range(startEyeC,startEyeC+glassWidth));
    cv::Mat chicoEyeRoiChannels[3];
    cv::split(chicoEyeRoi,chicoEyeRoiChannels);
    
    cv::Mat maskedEyeChicoChannels[3];
    cv::Mat maskedEyeChico;

    for (int i = 0; i < 3; i++)
    {
         multiply(chicoEyeRoiChannels[i], (1-glassMaskChannels[i]), maskedEyeChicoChannels[i]);
    }
    cv::merge(maskedEyeChicoChannels,3,maskedEyeChico);
    
    cv::Mat maskedChicoGlass;
    multiply(glassBgr,glassMask,maskedChicoGlass);

    cv::Mat eyeChicoRoiFinal;
    cv::add(maskedEyeChico,maskedChicoGlass,eyeChicoRoiFinal);
    
    eyeChicoRoiFinal.copyTo(chicoEyeRoi);
    cv::imshow("chico", chicoGlasses);
    
    cv::waitKey(0);
    return 0;
}
