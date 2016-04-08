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
//    std::cout << "patch::patch()" << std::endl;
    width = 30;
    
}

patch::patch(cv::Mat baseImage, cv::Point coords, int widthVal)
{
//    std::cout << "patch::patch()" << std::endl;
    make(baseImage,coords,widthVal);
}

void patch::make(cv::Mat baseImage, cv::Point coords)
{    // check boundaries of baseImage to make sure that patch will fit
//    std::cout << "patch::make()" << std::endl;
    int baseX = baseImage.cols;
    int baseY = baseImage.rows;
//    std:: cout << "Checking Patch Fit " << std::endl;
//std::cout << "patch coordinates: " << coords.x << ", " << coords.y << std::endl;
    if (baseX - coords.x >= width/2)
    {
        if (coords.x >= width/2 + 1)
        {
            coordinates.x = coords.x - 1;
        }
        else coordinates.x = width/2 + 1;
    }
    else coordinates.x = baseX - width/2 - 1;
    if (baseY - coords.y >= width/2)
    {
        if (coords.y >= width/2 + 1)
        {
            coordinates.y = coords.y - 1;
        }
        else coordinates.y = width/2 + 1;
    }
    else coordinates.y = baseY - width/2 - 1;
    
//	std::cout << "baseImage(Rect()).copyTo(image);" << std::endl;
//    std::cout << "patch coordinates: " << coordinates.x << ", " << coordinates.y << std::endl;
//    std::cout << "patch Image: cols: " << image.cols << ", rows: " << image.rows << std::endl;
//    std::cout << "patch width: " << width << std::endl;
//    std::cout << "baseImage: cols: " << baseImage.cols << ", rows: " << baseImage.rows << std::endl;
//    cv::imshow("patch image", image);
//    cv::imshow("base Image", baseImage(Rect(coordinates.x - (width/2), coordinates.y - (width/2), (width+1), (width+1))));
//    waitKey(0);
    baseImage(Rect(coordinates.x - width/2, coordinates.y - width/2, width+1, width+1)).copyTo(image);
//	std::cout << "baseImage DONE" << std::endl;
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
    int baseX = baseImage.cols-1;
    int baseY = baseImage.rows-1;
    std:: cout << "Checking Patch Fit " << std::endl;
    if (baseX - coords.x >= width/2) // not too far to the right
    {
        if (coords.x >= width/2 + 1) // not too far to the left
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
    
//	std::cout << "baseImage(Rect()).copyTo(image);" << std::endl;
    baseImage(Rect(coordinates.x - width/2, coordinates.y - width/2, width+1, width+1)).copyTo(image);
//	std::cout << "baseImage DONE" << std::endl;
}

void patch::redraw(cv::Mat baseImage)
{
//    std::cout << "patch::redraw()" << std::endl;
//    std::cout << "patch coordinates: " << coordinates.x << ", " << coordinates.y << std::endl;
//    std::cout << "patch Image: cols: " << image.cols << ", rows: " << image.rows << std::endl;
//    std::cout << "patch width: " << width << std::endl;
//    std::cout << "baseImage: cols: " << baseImage.cols << ", rows: " << baseImage.rows << std::endl;
//    cv::imshow("patch image", image);
//    cv::imshow("base Image", baseImage(Rect(coordinates.x - (width/2), coordinates.y - (width/2), (width+1), (width+1))));
//    waitKey(0);
    image.copyTo(baseImage(Rect(coordinates.x - (width/2), coordinates.y - (width/2), (width+1), (width+1))));
}
