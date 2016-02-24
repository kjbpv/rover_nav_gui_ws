//
//  rover.h
//  RoverNavigationGUI_1
//
//  Created by kyle brown on 1/21/16.
//  Copyright (c) 2016 Kyle Brown. All rights reserved.
//

#ifndef RoverNavigationGUI_1_rover_h
#define RoverNavigationGUI_1_rover_h

#include <iostream>
#include <fstream>
#include <string.h>
#include "waypoint.h"

using namespace std;

class rover : public waypoint
{
public:
    rover();
    rover(std::string filename);
    ~rover(){}
    void init(std::string filename);
    double getMagHeading();
    double getAngle();
    
    void setMagHeading(double val);
    void setAngle(double val);
    
    void readData();
    
private:
    double magHeading;
    double angle; // in degrees
    ifstream dataFile;
    
};

#endif
