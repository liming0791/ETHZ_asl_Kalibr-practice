#include "stdio.h"
#include "stdlib.h"
#include <iostream>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {

    FILE * file = fopen(argv[1], "rb");

    size_t res = 0;
    while (true) {
        unsigned int timeStamp = 0;
        int width, height;

        res = fread(&timeStamp, sizeof(unsigned int), 1, file);
        if (res != 1) break;
        unsigned long timeStamp_long = timeStamp;
        printf("time: %012lu\n", timeStamp_long*1000);

        res = fread(&width, sizeof(int), 1, file);
        if (res != 1) break;
        printf("w: %d\n", width);

        res = fread(&height, sizeof(int), 1, file);
        if (res != 1) break;
        printf("h: %d\n", height);

        cv::Mat image(height, width, CV_8UC1);
        res = fread(image.data, sizeof(unsigned char), width*height, file);
        if (res != size_t(height*width)) break;

        cv::Mat rgb;
        cv::cvtColor(image, rgb, CV_GRAY2BGR);

        char name[50] = "";
        sprintf(name, "%012lu.png", timeStamp_long*1000);

        cv::imwrite(name, rgb);

    }

}
