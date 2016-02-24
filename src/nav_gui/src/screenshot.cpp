//
//  screenshot.cpp
//  
//
//  Created by kyle brown on 1/22/16.
//
//

#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "screenshot.h"

using namespace cv;
using namespace std;


screenshot::screenshot()
{
    cout << "screenshot::screenshot()" << endl;
}
screenshot::screenshot(cv::Mat IMG, double latVal, double longVal, cv::Point origin, double LATconversion, double LONGconversion, double MperPix)
{
    cout << "screenshot::screenshot()" << endl;
    image = IMG;
    latitude = latVal;
    longitude = longVal;
    pixelOrigin = origin;
    PixelsPerLAT = LATconversion;
    PixelsPerLONG = LONGconversion;
    MetersPerPixel = MperPix;
}

void screenshot::init(cv::Mat IMG, double latVal, double longVal, cv::Point origin, double LATconversion, double LONGconversion, double MperPix)
{
    cout << "screenshot::init()" << endl;
    image = IMG;
    latitude = latVal;
    longitude = longVal;
    pixelOrigin = origin;
    PixelsPerLAT = LATconversion;
    PixelsPerLONG = LONGconversion;
    MetersPerPixel = MperPix;
}

cv::Mat screenshot::getImage()
{
    cout << "screenshot::getImage()" << endl;
    return image;
}

double screenshot::getLatitude()
{
    cout << "screenshot::getLatitude()" << endl;
    return latitude;
}

double screenshot::getLongitude()
{
    cout << "screenshot::getLongitude()" << endl;
    return longitude;
}

cv::Point screenshot::getpixelOrigin()
{
    cout << "screenshot::getPixelOrigin()" << endl;
    return pixelOrigin;
}

double screenshot::getPixelsPerLAT()
{
    cout << "screenshot::getOixelsPerLAT()" << endl;
    return PixelsPerLAT;
}

double screenshot::getPixelsPerLONG()
{
    cout << "screenshot::getPixelsPerLONG()" << endl;
    return PixelsPerLONG;
}

double screenshot::getMetersPerPixel()
{
    cout << "screenshot::getMetersPerPixel()" << endl;
    return MetersPerPixel;
}

cv::Point screenshot::calculateCoords(double latVal, double longVal)
{
    cout << "screenshot::calculateCoords()" << endl;
    cv::Point coordinates;
//    std::cout << "longVal: " << longVal << std::endl;
//    std::cout << "latVal: " << latVal << std::endl;
//    std::cout << "longitude: " << longitude << std::endl;
//    std::cout << "latitude: " << latitude << std::endl;
    
    double x = (longVal - longitude)*PixelsPerLONG + pixelOrigin.x;
    double y = (latVal - latitude)*PixelsPerLAT + pixelOrigin.y;
//    std::cout << "X: " << x << ", Y: " << y << std::endl;
    
    coordinates.x = x;
    coordinates.y = y;
    
    return coordinates;
}

void screenshot::setImage(cv::Mat img)
{
    cout << "screenshot::setImage()" << endl;
    image = img;
}
void screenshot::setLatitude(double val)
{
    cout << "screenshot::setLatitude()" << endl;
    latitude = val;
}
void screenshot::setLongitude(double val)
{
    cout << "screenshot::setLongitude()" << endl;
    longitude = val;
}
void screenshot::setPixelOrigin(cv::Point origin)
{
    cout << "screenshot::setPixelOrigin()" << endl;
    pixelOrigin  = origin;
}
void screenshot::setPixelsPerLAT(double val)
{
    cout << "screenshot::setPixelsPerLAT()" << endl;
    PixelsPerLAT = val;
}
void screenshot::setPixelsPerLONG(double val)
{
    cout << "screenshot::setPixelsPerLONG()" << endl;
    PixelsPerLONG = val;
}
void screenshot::setMetersPerPixel(double val)
{
    cout << "screenshot::setMetersPerPixel()" << endl;
    MetersPerPixel = val;
}



