//
//  patch.cpp
//  
//
//  Created by kyle brown on 1/22/16.
//
//

#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <iostream>
#include "patch.h"

using namespace cv;

patch::patch()
{
    std::cout << "patch::patch()" << std::endl;
    width = 30;
    
}

patch::patch(cv::Mat baseImage, cv::Point coords, int widthVal)
{
    std::cout << "patch::patch()" << std::endl;
    make(baseImage,coords,widthVal);
}

void patch::make(cv::Mat baseImage, cv::Point coords)
{    // check boundaries of baseImage to make sure that patch will fit
    std::cout << "patch::make()" << std::endl;
    int baseX = baseImage.cols;
    int baseY = baseImage.rows;
    if (baseX - coords.x >= width/2)
    {
        if (coords.x >= width/2 + 1)
        {
            coordinates.x = coords.x;
        }
        else coordinates.x = width/2 + 1;
    }
    else coordinates.x = baseX - width/2;
    if (baseY - coords.y >= width/2)
    {
        if (coords.y >= width/2 + 1)
        {
            coordinates.y = coords.y;
        }
        else coordinates.y = width/2 + 1;
    }
    else coordinates.y = baseY - width/2;
    
	std::cout << "baseImage(Rect()).copyTo(image);" << std::endl;
    baseImage(Rect(coordinates.x - width/2, coordinates.y - width/2, width+1, width+1)).copyTo(image);
	std::cout << "baseImage DONE" << std::endl;
}

void patch::make(cv::Mat baseImage, cv::Point coords, int widthVal)
{
    std::cout << "patch::make()" << std::endl;
    coordinates = cv::Point(0,0);
    // set width
    if (widthVal%2 == 1)
    {
        width = widthVal - 1;
    }
    else width = widthVal;
    
    // check boundaries of baseImage to make sure that patch will fit
    int baseX = baseImage.cols;
    int baseY = baseImage.rows;
    if (baseX - coords.x >= width/2)
    {
        if (coords.x >= width/2 + 1)
        {
            coordinates.x = coords.x;
        }
        else coordinates.x = width/2 + 1;
    }
    else coordinates.x = baseX - width/2;
    if (baseY - coords.y >= width/2)
    {
        if (coords.y >= width/2 + 1)
        {
            coordinates.y = coords.y;
        }
        else coordinates.y = width/2 + 1;
    }
    else coordinates.y = baseY - width/2;
    
	std::cout << "baseImage(Rect()).copyTo(image);" << std::endl;
    baseImage(Rect(coordinates.x - width/2, coordinates.y - width/2, width+1, width+1)).copyTo(image);
	std::cout << "baseImage DONE" << std::endl;
}

void patch::redraw(cv::Mat baseImage)
{
    std::cout << "patch::redraw()" << std::endl;
    image.copyTo(baseImage(Rect(coordinates.x - width/2, coordinates.y - width/2, width+1, width+1)));
}
