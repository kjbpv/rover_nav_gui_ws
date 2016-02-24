//
//  main.cpp
//  NAV_GUI_1
//
//  Created by kyle brown on 1/28/16.
//  Copyright (c) 2016 Kyle Brown. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include <string.h>
#include "display.h"
#include "rover.h"
#include "waypoint.h"
#include "patch.h"
#include "screenshot.h"


using namespace std;
using namespace cv;

int main(int argc, const char * argv[])
{
    cout << "OpenCV version: " << CV_VERSION << endl;
    
    string mapFile = "AstronautAssist1.png";
    string radarFile = "radar.png";
    string dataFile = "roverData.txt";
    display myDisplay(mapFile,radarFile,dataFile);
    
    for (int i = 0; i < 210; i++)
    {
        myDisplay.updateRover();
        myDisplay.rotateRadar();
        myDisplay.drawWaypoints();
        myDisplay.drawRover();
        myDisplay.updateDisplay();
        waitKey(100);
    }
    
    waitKey();
    
    return 0;
}
