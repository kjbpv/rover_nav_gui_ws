//
//  display.h
//  RoverNavigationGUI_1
//
//  Created by kyle brown on 1/21/16.
//  Copyright (c) 2016 Kyle Brown. All rights reserved.
//

#ifndef RoverNavigationGUI_1_display_h
#define RoverNavigationGUI_1_display_h

// display class
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include <string.h>
#include "waypoint.h"
#include "rover.h"
#include "patch.h"
#include "screenshot.h"

#define pi 3.14159

class display
{
public:
    display(string mapFile, string radarFile, string dataFile);
    ~display(){}
    void drawTriangle(cv::Mat img, int base, int height, int angle, cv::Point center, cv::Scalar color);
    // void drawCircle(cv::Mat img, cv::Point center, int radius, cv::Scalar color); // do I need this
    // void drawSquare(cv::Point center,int width, cv::Scalar color);
    /* Update the following:
     
     Rover Position
     Radar orientation
     Waypoint positions on radar
     Text specifying waypoint distances
     
     */
    void updateDisplay();
    void updateRover();
    void rotateRadar();
    void drawWaypoints();
    void drawRover();
    double getDistance(waypoint p1, waypoint p2);
    double getAngle(waypoint p1, waypoint p2);
    void addWaypoint(string name, double latitude, double longitude);
    void addPatch(waypoint myWaypoint);
    
    /* Mat mainBox - contains the entire GUI window*/
    cv::Mat mainBox;
    /* Mat mapBox - subregion of mainBox that contains the  map image */
    cv::Mat mapBox;
    /* Mat radarBox - subregion of mainBox that contains the radar plot */
    cv::Mat radarBox;
    cv::Mat radarBase;
    cv::Mat radarImg;
    
    waypoint* target;
    screenshot myMap;
    // Contains all waypoints
    std::vector<waypoint> waypoints;
    std::vector<patch> patches;
    patch roverPatch;
    rover mRover;
    
private:
};

#endif
