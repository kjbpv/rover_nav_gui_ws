//
//  rover.cpp
//  
//
//  Created by kyle brown on 1/21/16.
//
//

#include <stdio.h>
#include "rover.h"
#include <iostream>
#include <string.h>

rover::rover()
{
    waypoint();
}

rover::rover(std::string filename)
{
    waypoint();
    dataFile.open(filename.c_str());
    readData();
}

void rover::init(std::string filename)
{
    dataFile.open(filename.c_str());
    readData();
}

double rover::getMagHeading()
{
    return magHeading;
}

double rover::getAngle()
{
    return angle;
}

void rover::setMagHeading(double val)
{
    magHeading = val;
}

void rover::setAngle(double val)
{
    angle = val;
}

void rover::readData()
{
    double temp1, temp2, temp3;
    dataFile >> temp1 >> temp2 >> temp3;
    if (!dataFile.fail())
    {
        setLatitude(temp1);
        setLongitude(temp2);
        magHeading = temp3;
    }
    else cout << "dataFile failed!";
}
