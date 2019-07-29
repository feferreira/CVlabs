#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(){
    string faceImagePath = "../input/musk.jpg";
    string glassimagePath = "../input/sunglass.png";
    
    Mat faceImage = imread(faceImagePath);
    Mat glassPng = imread(glassimagePath, -1);
    
    resize(glassPng, glassPng, Size(300,100));
    
    cout << "image dimension " << glassPng.size() << endl;
    cout << "image channels " << glassPng.channels() << endl;
    
    Mat glassRGBAChannels[4];
    Mat glassRGBChannels[3];
    split(glassPng, glassRGBAChannels);
    
    for(int i=0; i < 3; i++){
        glassRGBChannels[i] = glassRGBAChannels[i];
    }
    
    Mat glassBGR, glassMask1;
    
    //cria uma imagem BGR
    merge(glassRGBChannels,3,glassBGR);
    
    glassMask1 = glassRGBAChannels[3];
    
    imwrite("../output/sunglassRGB.png", glassBGR);
    imwrite("../output/sunglassAlpha.png", glassMask1);
    
    Mat faceWithGlassesNaive = faceImage.clone();
    Mat roiFace = faceWithGlassesNaive(Range(150,250),Range(140,440));
    
    glassBGR.copyTo(roiFace);
    
    imwrite("../output/faceWithGlassesNaive.png", faceWithGlassesNaive);
    
    // Make the dimensions of the mask same as the input image.
    // Since Face Image is a 3-channel image, we create a 3 channel image for the mask
    Mat glassMask;
    Mat glassMaskChannels[] = {glassMask1, glassMask1, glassMask1};
    merge(glassMaskChannels, 3, glassMask);
    
    // Make the values [0,1] since we are using arithmetic operations
    glassMask = glassMask/255;
    
    Mat faceWithGlassesArithmetic = faceImage.clone();

    // Get the eye region from the face image
    Mat eyeRoi = faceWithGlassesArithmetic(Range(150,250),Range(140,440));
    
    Mat eyeRoiChannels[3];
    split(eyeRoi,eyeRoiChannels);
    Mat maskedEyeChannels[3];
    Mat maskedEye;
    
    for (int i = 0; i < 3; i++){
        // Use the mask to create the masked eye region
        multiply(eyeRoiChannels[i], (1-glassMaskChannels[i]), maskedEyeChannels[i]);
    }
    merge(maskedEyeChannels,3,maskedEye);
    
    Mat maskedGlass;
    
    // Use the mask to create the masked sunglass region
    multiply(glassBGR, glassMask, maskedGlass);
    
    Mat eyeRoiFinal;
    // Combine the Sunglass in the Eye Region to get the augmented image
    add(maskedEye, maskedGlass, eyeRoiFinal);
    
    imwrite("../output/maskedEyeRegion.png",maskedEye);
    imwrite("../output/maskedSunglassRegion.png",maskedGlass);
    imwrite("../output/augmentedEyeAndSunglass.png",eyeRoiFinal);
    
    eyeRoiFinal.copyTo(eyeRoi);
    
    imwrite("../output/withSunglasses.png", faceWithGlassesArithmetic);
}
