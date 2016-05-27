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
#define BLUE 255,0,0
#define GREEN 0,255,0
#define RED 0,0,255
#define PURPLE 255,0,255
#define YELLOW 0,255,255

class display
{
public:
    display(){}
    display(string mapImageFile, string radarFile, string waypointFile, string obstacleFile, string anchorFile, string mapInitFile);
    ~display(){}
    void drawTriangle(cv::Mat img, int base, int height, int angle, cv::Point center, cv::Scalar color);
    void drawSquare(cv::Mat img, int base, int height, cv::Point center, cv::Scalar color);
    void drawX(cv::Mat img, int base, int height, int angle, cv::Point center, cv::Scalar color);

    void init(string mapImageFile, string radarFile, string waypointFile, string obstacleFile, string anchorFile, string mapInitFile);
    void reinit(string mapImageFile);
    void updateDisplay(); // displays entire GUI window
    void updateDisplayMini(); // displays entire GUI window in miniature size (for lower screen resolutions)
    void updateRover();
    void updateRover(double latVal, double longVal, double magVal);
    void rotateRadar();
    void drawWaypoints();
    void drawObstacles();
    void drawAnchor();
    void drawRover();
    void drawRover(int dX, int dY);
    double getDistance(waypoint p1, waypoint p2);
    double getPixelDistance(waypoint p1, waypoint p2);
    double getAngle(waypoint p1, waypoint p2);
    void addWaypoint(string name, double latitude, double longitude);
    void addObstacle(string name, double latitude, double longitude);
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
    waypoint anchor;
    screenshot myMap;
    // Contains all waypoints
    std::vector<waypoint> waypoints;
    std::vector<waypoint> obstacles;
    std::vector<patch> patches;
    patch roverPatch;
    rover mRover;
    
private:
};

#endif
