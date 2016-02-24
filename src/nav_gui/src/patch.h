//
//  patch.h
//  RoverNavigationGUI_1
//
//  Created by kyle brown on 1/22/16.
//  Copyright (c) 2016 Kyle Brown. All rights reserved.
//

#ifndef RoverNavigationGUI_1_patch_h
#define RoverNavigationGUI_1_patch_h

#include <iostream>
#include <opencv2/opencv.hpp>

class patch
{
public:
    patch();
    patch(cv::Mat baseImage, cv::Point coords, int widthVal);
    ~patch(){}
    void make(cv::Mat baseImage, cv::Point coords);
    void make(cv::Mat baseImage, cv::Point coords, int widthVal);
    void redraw(cv::Mat baseImage);
    
private:
    cv::Mat image;
    cv::Point coordinates;
    int width;
    
};

#endif
