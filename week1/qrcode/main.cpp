#include <iostream>
#include "qrdetector.h"

int main(){
    QrDetector detector;
    while(!detector.runDetector());
    return 0;
}
