//
//  waypoint.h
//  RoverNavigationGUI_1
//
//  Created by kyle brown on 1/21/16.
//  Copyright (c) 2016 Kyle Brown. All rights reserved.
//

#ifndef RoverNavigationGUI_1_waypoint_h
#define RoverNavigationGUI_1_waypoint_h

#include <opencv2/opencv.hpp>
#include <iostream>
#include "screenshot.h"

class waypoint
{
public:
    waypoint();
    waypoint(std::string nameVal, double latVal, double longVal);
    ~waypoint(){}
    double getLatitude();
    double getLongitude();
    double getAngleFromRover();
    double getDistanceToRover();
    cv::Point getCoordinates();
    
    void setLatitude(double val);
    void setLongitude(double val);
    void setCoordinates(screenshot myMap);
    void setCoordinates(cv::Point);
    void setCoordinates(int X, int Y);
    void setX(int val);
    void setY(int val);
    void setTarget(bool val);
    void setDistanceToRover(double val);
    void setAngleFromRover(double val);
    
private:
    std::string name;
    bool isTarget; // Only one waypoint should be the target at a given time
    
    double latitude;
    double longitude;
    
    // distance in meters
    double distanceToRover;
    
    // angle from rover's heading (CCW)
    double angleFromRover;
    
    // X,Y coordinates in pixels
    cv::Point coordinates;
//    double angle;
    
};

#endif
