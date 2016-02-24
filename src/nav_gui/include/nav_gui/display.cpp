//
//  display.cpp
//
//
//  Created by kyle brown on 1/29/16.
//
//

#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include "display.h"

using namespace std;
using namespace cv;

display::display(string mapFile, string radarFile, string dataFile) : mRover(dataFile)
{
    cout << "display::display()" << endl;
    mainBox = cv::Mat(660,1280,CV_8UC3,cv::Scalar(80,80,80));
    mapBox = mainBox(cv::Rect(10,10,800, 640));
    radarBox = mainBox(cv::Rect(820,10,450,450));
    cv::Mat img = cv::imread(mapFile);
    cv::pyrDown(img, img);
    img.copyTo(mapBox);
    
    radarBase = cv::imread(radarFile);
    radarBase.copyTo(radarImg);
    radarImg(cv::Rect(125,125,450,450)).copyTo(radarBox);
    
    // screenshot parameters
    double LATval = 38.417127;
    double LONGval = -110.787396;
    // DIVIDED by 2.0 because of pyrDown
    cv::Point ptOrigin((199-406)/2,(1404-120)/2); // was 199,1404
    double dYdLAT = -424443.706409723/2.0;
    double dXdLONG = 333722.798305457/2.0;
    double dMeterdPixel = 50.0/190.0;
    myMap.init(mapBox, LATval, LONGval, ptOrigin, dYdLAT, dXdLONG, dMeterdPixel);
    
    // add Waypoints
    addWaypoint("tools",38.419060,-110.786316);
    addWaypoint("hammer",38.418397,-110.785769);
    addWaypoint("screwdriver",38.419357,-110.783796);
    addWaypoint("wrench",38.418494,-110.783336);
    
    for (int i = 0; i < waypoints.size(); i++)
    {
        waypoints[i].setCoordinates(myMap);
    }
    
    roverPatch.make(myMap.getImage(), Point(30,30),30);
   
    cout << "cv::namedindow()" << endl;
    cv::namedWindow("mainWindow",cv::WINDOW_AUTOSIZE);
    cout << "cv::namedindow() DONE" << endl;
}

void display::drawTriangle(Mat img, int base, int height, int angle, Point center, Scalar color)
{
    cout << "display::drawTriangle()" << endl;
    angle = -angle;
    
    Point2f p1(base/2,height/2);
    Point2f p2(-base/2,height/2);
    Point2f p3(0,-height/2);
    
    double tempX = (p1.x)*cos(pi*angle/180.0) - (p1.y)*sin(pi*angle/180.0);
    double tempY = (p1.x)*sin(pi*angle/180.0) + (p1.y)*cos(pi*angle/180.0);
    p1.x = tempX + center.x;
    p1.y = tempY + center.y;
    
    tempX = (p2.x)*cos(pi*angle/180.0) - (p2.y)*sin(pi*angle/180.0);
    tempY = (p2.x)*sin(pi*angle/180.0) + (p2.y)*cos(pi*angle/180.0);
    p2.x = tempX + center.x;
    p2.y = tempY + center.y;
    
    tempX = (p3.x)*cos(pi*angle/180.0) - (p3.y)*sin(pi*angle/180.0);
    tempY = (p3.x)*sin(pi*angle/180.0) + (p3.y)*cos(pi*angle/180.0);
    p3.x = tempX + center.x;
    p3.y = tempY + center.y;
    
    Point triangle[1][3];
    triangle[0][0] = Point(p1.x,p1.y);
    triangle[0][1] = Point(p2.x,p2.y);
    triangle[0][2] = Point(p3.x,p3.y);
    
    const Point* ppt[1] = { triangle[0] };
    
    int npt[] = {3};
    
    fillPoly(img, ppt, npt, 1, color);
}

// void drawCircle(cv::Mat img, cv::Point center, int radius, cv::Scalar color); // do I need this
// void drawSquare(cv::Point center,int width, cv::Scalar color);
/* Update the following:
 
 Rover Position
 Radar orientation
 Waypoint positions on radar
 Text specifying waypoint distances
 
 */
void display::updateDisplay()
{
    cout << "display::updateDisplay()" << endl;
    cv::imshow("mainWindow", mainBox);
}

void display::updateRover()
{
    cout << "display::updateRover()" << endl;
    // Read in rover data from file
    mRover.readData();
    
    // Convert magheading to angle value
    mRover.setAngle(mRover.getMagHeading());
    
    // Calculate rover coordinates based on screenshot parameters
    
    mRover.setCoordinates(myMap);
}

void display::rotateRadar()
{
    cout << "display::rotateRadar()" << endl;
    cout << "display::drawRover()" << endl;
    Mat rotationMatrix;
    rotationMatrix = getRotationMatrix2D(Point2f(350,350), -1.0*mRover.getAngle(), 1.0);
    // rotate radar image based on rover angle
    cv::warpAffine(radarBase, radarImg, rotationMatrix, radarBase.size());
    // copy rotated image from radarBox to radar
    radarImg(Rect(125,125,450,450)).copyTo(radarBox);
}

void display::drawWaypoints()
{
    cout << "display::drawWaypoints()" << endl;
    double shortestDistance = getDistance(waypoints[0], mRover) + 1.0;
    target = &waypoints[0];
    for (int i = 0; i < waypoints.size(); i++)
    {
        
        waypoints[i].setDistanceToRover(getDistance(waypoints[i], mRover));
        if (waypoints[i].getDistanceToRover() < shortestDistance)
        {
            shortestDistance = waypoints[i].getDistanceToRover();
            target = &waypoints[i];
        }
        waypoints[i].setAngleFromRover(getAngle(waypoints[i], mRover));
        cout << "ANGLE: " << waypoints[i].getAngleFromRover() << endl;
    }
    
    // draw waypoints on map, with target highlighted in yellow
    for (int i = 0; i < waypoints.size(); i++)
    {
        drawTriangle(myMap.getImage(), 12, 10, 0, waypoints[i].getCoordinates(), Scalar(0,0,255));
    }
    drawTriangle(myMap.getImage(), 12, 10, 0, target->getCoordinates(), Scalar(0,255,255));
    
    // draw waypoints within radarBox
    double radarRadius = 180;
    for (int i = 0; i < waypoints.size(); i++)
    {
        if (waypoints[i].getDistanceToRover() < 50)
        {
            drawTriangle(radarBox, 12, 10, 0, Point(225 + cos(waypoints[i].getAngleFromRover()+mRover.getAngle()*pi/180)*radarRadius*waypoints[i].getDistanceToRover()/50.0, 225 + sin(waypoints[i].getAngleFromRover()+mRover.getAngle()*pi/180)*radarRadius*waypoints[i].getDistanceToRover()/50.0), Scalar(0,0,255));
        }
        else
        {
            drawTriangle(radarBox, 12, 10, 0, Point(225 + cos(waypoints[i].getAngleFromRover()+mRover.getAngle()*pi/180)*radarRadius, 225 + sin(waypoints[i].getAngleFromRover()+mRover.getAngle()*pi/180)*radarRadius), Scalar(0,0,255));
        }
    }
    
    // draw Target waypoint on radar
    if (target->getDistanceToRover() < 50)
    {
        drawTriangle(radarBox, 12, 10, 0, Point(225 + cos(target->getAngleFromRover()+mRover.getAngle()*pi/180)*radarRadius*target->getDistanceToRover()/50.0, 225 + sin(target->getAngleFromRover()+mRover.getAngle()*pi/180)*radarRadius*target->getDistanceToRover()/50.0), Scalar(0,255,255));
    }
    else
    {
        drawTriangle(radarBox, 12, 10, 0, Point(225 + cos(target->getAngleFromRover()+mRover.getAngle()*pi/180)*radarRadius*target->getDistanceToRover()/50.0,225 + sin(target->getAngleFromRover()+mRover.getAngle()*pi/180)*radarRadius*target->getDistanceToRover()/50.0), Scalar(0,255,255));
    }
}

void display::drawRover()
{
    cout << "display::drawRover()" << endl;
    // draw patch to cover previous rover
    
    roverPatch.redraw(myMap.getImage());
    
    // Take patch to cover up rover in next frame
    
    roverPatch.make(myMap.getImage(), mRover.getCoordinates());

    
    // draw the rover triangle within the radar box
    drawTriangle(radarBox, 20, 32, 0, Point(223,225), Scalar(255,255,255));
    
    // draw the rover triangle on the map screenshot
    drawTriangle(myMap.getImage(), 6, 10, mRover.getAngle(), mRover.getCoordinates(), Scalar(0,255,0)); // rover
}

double display::getDistance(waypoint p1, waypoint p2)
{
    cout << "display::getDistance()" << endl;
    double distanceX,distanceY,distance;
    distanceX = (p1.getLongitude()-p2.getLongitude())*myMap.getPixelsPerLONG()*myMap.getMetersPerPixel();
    distanceY = (p1.getLatitude()-p2.getLatitude())*myMap.getPixelsPerLAT()*myMap.getMetersPerPixel();
    distance = sqrt(distanceX*distanceX + distanceY*distanceY);
    return distance;
}

double display::getAngle(waypoint p1, waypoint p2)
{
    cout << "display::getAngle()" << endl;
    double angle = atan2((p1.getCoordinates().y - p2.getCoordinates().y) , (p1.getCoordinates().x - p2.getCoordinates().x));
    return angle;
}

void display::addWaypoint(string name, double latitude, double longitude)
{
    cout << "display::addWaypoint()" << endl;
    waypoints.push_back(waypoint(name,latitude,longitude));
}

void display::addPatch(waypoint myWaypoint)
{
    cout << "display::addPatch()" << endl;
}


