#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

int main(){
    //set path's
    const char * sunglassPath = "../images/sunglasses.png";
    const char * billiePath = "../images/billie.jpg";
    //open image files
    cv::Mat sunglasses = cv::imread(sunglassPath, cv::IMREAD_UNCHANGED);
    cv::Mat billie = cv::imread(billiePath);
        
    std::cout << "size of sunglasses: " << sunglasses.size() << '\n';
    std::cout << "size of billie: " << billie.size() << '\n';
    std::cout << "channels of sunglasses: " << sunglasses.channels() << '\n';
    std::cout << "channels of billie: " << billie.channels() << '\n';
    
    //resize sunglasses to fit in images
    cv::resize(sunglasses, sunglasses, cv::Size(100,80));
    int glassHeight = sunglasses.size().height;
    int glassWidth = sunglasses.size().width;
    
    cv::Mat billieWithGlassBitwise = billie.clone();

    cv::Mat glassRgbaChannels[4];
    cv::Mat glassRgbChannels[3];

    cv::split(sunglasses, glassRgbaChannels);
    for(int i = 0; i <3; i++){
        glassRgbChannels[i] = glassRgbaChannels[i];
    }
    cv::Mat glassBgr, glassMask1;
    cv::merge(glassRgbChannels,3,glassBgr);
    glassMask1 = glassRgbaChannels[3];

    int startEyeR = 160;
    int startEyeC = 85;
    cv::Mat eyeRoi = billieWithGlassBitwise(cv::Range(startEyeR,startEyeR+glassHeight),
            cv::Range(startEyeC,startEyeC+glassWidth));
    cv::Mat glassMask;
    cv::Mat glassMaskChannels[]={glassMask1, glassMask1, glassMask1};
    cv::merge(glassMaskChannels,3,glassMask);
    cv::Mat glassMaskNot;
    cv::bitwise_not(glassMask1, glassMaskNot);
    cv::Mat eye;
    cv::Mat eyeChannels[3];
    cv::Mat eyeRoiChannels[3];
    cv::Mat maskedGlass;
    cv::Mat eyeRoifinal;
    cv::split(eyeRoi, eyeRoiChannels);
    for(int i=0; i<3; i++){
        cv::bitwise_and(eyeRoiChannels[i],glassMaskNot,eyeChannels[i]);
    }
    
    std::cout << "cheguei\n";    
    cv::Mat glassMaskNotChannels[]={glassMaskNot, glassMaskNot, glassMaskNot};
    cv::Mat glassNotMerged;
    cv::merge(glassMaskNotChannels,3,glassNotMerged);

    cv::bitwise_and(eyeRoi, glassNotMerged, eye);

    cv::Mat sunglassRegion;
    cv::Mat sunglassRegionChannels[3];
    cv::Mat glassRegionBgrChannels[3];

    split(glassBgr, glassRegionBgrChannels);
    for(int i=0; i<3; i++){
        cv::bitwise_and(glassRegionBgrChannels[i], glassMask1, sunglassRegionChannels[i]);
    }
    
    cv::merge(sunglassRegionChannels,3,sunglassRegion);

    cv::multiply(glassBgr, glassMask, maskedGlass);

    cv::bitwise_or(eye,sunglassRegion,eyeRoifinal);
    eyeRoifinal.copyTo(eyeRoi);

    cv::imshow("billie", billieWithGlassBitwise);
    
    cv::waitKey(0);
    return 0;
}
