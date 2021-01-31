#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

int main(){
    const char * sunglassPath = "../images/sunglasses.png";
    const char * chicoPath = "../images/chico.jpg";
    const char * billiePath = "../images/billie.jpg";
    cv::Mat sunglasses = cv::imread(sunglassPath, cv::IMREAD_UNCHANGED);
    cv::Mat chico = cv::imread(chicoPath);
    cv::Mat billie = cv::imread(billiePath);
    //cv::resize(sunglasses,sunglasses, cv::Size(300,100));    
    std::cout << "size of sunglasses: " << sunglasses.size() << '\n';
    std::cout << "size of chico: " << chico.size() << '\n';
    std::cout << "size of billie: " << billie.size() << '\n';
    std::cout << "channels of sunglasses: " << sunglasses.channels() << '\n';
    std::cout << "channels of chico: " << chico.channels() << '\n';
    std::cout << "channels of billie: " << billie.channels() << '\n';
    cv::resize(sunglasses, sunglasses, cv::Size(100,80));
    int glassHeight = sunglasses.size().height;
    int glassWidth = sunglasses.size().width;
    //separate channels of sunglasses
    cv::Mat glassRgbaChannels[4];
    cv::Mat glassRgbChannels[3];
    cv::split(sunglasses, glassRgbaChannels);
    //separate glass mask from glassBgr
    for(int i = 0; i < 3; i++){
        glassRgbChannels[i] = glassRgbaChannels[i];
    }

    cv::Mat glassBgr, glassMask1;
    cv::merge(glassRgbChannels,3,glassBgr);
    glassMask1 = glassRgbaChannels[3];
    //make the glass mask the same channels as the image
    cv::Mat glassMaskChannels[3] = {glassMask1, glassMask1, glassMask1};
    cv::Mat glassMask;
    cv::merge(glassMaskChannels,3,glassMask);
    
    glassMask = glassMask/255;
    cv::Mat chicoGlasses = chico.clone();
    cv::Mat billieGlasses = billie.clone();
    // get the eye region
    std::cout << "pegando regiao\n";
    cv::Mat chicoRoi = chicoGlasses(cv::Range(180,180+glassHeight),
            cv::Range(85,85+glassWidth));
    cv::Mat billieRoi = billieGlasses(cv::Range(0,40),cv::Range(0,100));
    std::cout << "peguei regiao\n";
    
    cv::Mat chicoRoiChannels[3];
    cv::split(chicoRoi,chicoRoiChannels);
    
    cv::Mat billieRoiChannels[3];
    cv::split(billieRoi,billieRoiChannels);
    
    cv::Mat maskedChicoChannels[3];
    cv::Mat maskedChico;

    cv::Mat maskedBillieChannels[3];
    cv::Mat maskedBillie;

    for (int i = 0; i < 3; i++)
    {
        //Use the mask to create the masked eye region
         multiply(chicoRoiChannels[i], (1-glassMaskChannels[i]), maskedChicoChannels[i]);
    }
    cv::merge(maskedChicoChannels,3,maskedChico);
    
    cv::Mat maskedChicoGlass;
    multiply(glassBgr,glassMask,maskedChicoGlass);

    cv::Mat eyeChicoRoiFinal;
    cv::add(maskedChico,maskedChicoGlass,eyeChicoRoiFinal);
    
    eyeChicoRoiFinal.copyTo(chicoRoi);
    cv::imshow("chico", chicoGlasses);
    cv::waitKey(0);
    
    return 0;
}
