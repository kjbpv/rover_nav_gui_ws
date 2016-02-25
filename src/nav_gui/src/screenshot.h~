//
//  screenshot.h
//  RoverNavigationGUI_1
//
//  Created by kyle brown on 1/22/16.
//  Copyright (c) 2016 Kyle Brown. All rights reserved.
//

#ifndef RoverNavigationGUI_1_screenshot_h
#define RoverNavigationGUI_1_screenshot_h

#include <iostream>
#include <opencv2/opencv.hpp>

class screenshot
{
public:
    screenshot();
    screenshot(cv::Mat IMG, double latVal, double longVal, cv::Point origin, double LATconversion, double LONGconversion, double MperPix);
    ~screenshot(){}
    void init(cv::Mat IMG, double latVal, double longVal, cv::Point origin, double LATconversion, double LONGconversion, double MperPix);
    cv::Mat getImage();
    double getLatitude();
    double getLongitude();
    cv::Point getpixelOrigin();
    double getPixelsPerLAT();
    double getPixelsPerLONG();
    double getMetersPerPixel();
    
    void setImage(cv::Mat img);
    void setLatitude(double val);
    void setLongitude(double val);
    void setPixelOrigin(cv::Point origin);
    void setPixelsPerLAT(double val);
    void setPixelsPerLONG(double val);
    void setMetersPerPixel(double val);
    
    cv::Point calculateCoords(double latVal, double longVal);
    
private:
    cv::Mat image;
    double latitude;
    double longitude;
    cv::Point pixelOrigin;
    double PixelsPerLAT;
    double PixelsPerLONG;
    double MetersPerPixel;
};

#endif
