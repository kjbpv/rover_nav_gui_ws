//
//  waypoint.cpp
//  
//
//  Created by kyle brown on 1/21/16.
//
//

#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "waypoint.h"

waypoint::waypoint()
{
    latitude = 0;
    longitude = 0;
    isTarget = false;
    name = "";
}

waypoint::waypoint(std::string nameVal, double latVal, double longVal)
{
    latitude = latVal;
    longitude = longVal;
    name = nameVal;
    isTarget = false;
}

double waypoint::getLatitude()
{
    return latitude;
}

double waypoint::getLongitude()
{
    return longitude;
}

cv::Point waypoint::getCoordinates()
{
    return coordinates;
}

double waypoint::getAngleFromRover()
{
    return angleFromRover;
}

double waypoint::getDistanceToRover()
{
    return distanceToRover;
}

void waypoint::setLatitude(double val)
{
    latitude = val;
}

void waypoint::setLongitude(double val)
{
    longitude = val;
}

void waypoint::setCoordinates(screenshot myMap)
{
    setCoordinates(myMap.calculateCoords(latitude, longitude));
}

void waypoint::setCoordinates(cv::Point coords)
{
    coordinates = coords;
}

void waypoint::setAngleFromRover(double val)
{
    angleFromRover = val;
}

void waypoint::setDistanceToRover(double val)
{
    distanceToRover = val;
}

void waypoint::setTarget(bool val)
{
    isTarget = val;
}