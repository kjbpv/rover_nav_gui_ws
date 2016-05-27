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

cv::Point waypoint::getOffset()
{
    return offset;
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

    coordinates = coordinates - offset;

    if (coordinates.x < 0)
    {
//	std::cout << "X: " << coordinates.x << ", Y: " << coordinates.y << std::endl;
	coordinates.x = 0;
    }
    if (coordinates.x >= myMap.image.cols)
    {
//	std::cout << "X: " << coordinates.x << ", Y: " << coordinates.y << std::endl;
	coordinates.x = myMap.image.cols - 1;
    }
    if (coordinates.y < 0)
    {
//	std::cout << "X: " << coordinates.x << ", Y: " << coordinates.y << std::endl;
	coordinates.y = 0;
    }
    if (coordinates.y >= myMap.image.rows)
    {
//	std::cout << "X: " << coordinates.x << ", Y: " << coordinates.y << std::endl;
	coordinates.y = myMap.image.rows - 1;
    }
}

void waypoint::setCoordinates(cv::Point coords)
{
    coordinates = coords;

}

void waypoint::setOffset(cv::Point coords)
{
    offset = coords;

}

void waypoint::setOffset(int x, int y)
{
    offset = cv::Point(x,y);

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
