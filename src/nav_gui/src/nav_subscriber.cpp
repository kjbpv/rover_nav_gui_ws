#include "ros/ros.h"
#include "opencv2/opencv.hpp"
#include "std_msgs/String.h"
#include "rover_msgs/NavState.h"
#include "waypoint.h"
#include "rover.h"
#include "screenshot.h"
#include "display.h"
#include <iostream>
#include <fstream>
#include <ctime>

// Global variables to store GPS and IMU data
double latitudeVal = 0;
double longitudeVal = 0;
double magHeadingVal = 0;

int dX = 0;
int dY = 0;
int mouseClickFlag = 0;

void navCallback(const rover_msgs::NavState::ConstPtr& stateMsg)
{
  latitudeVal = stateMsg->base_latitude;
  longitudeVal = stateMsg->base_longitude;
  magHeadingVal = stateMsg->psi*(180.0/3.14159);

//  ROS_INFO("I heard: [ %f , %f , %f ]", stateMsg->position[0], stateMsg->position[1], stateMsg->phi);
//  ROS_INFO("I heard: [ %f , %f , %f ]", latitudeVal, longitudeVal, magHeadingVal);
}

// Mouse click callback
void mouseCallBack(int event, int x, int y, int flags, void* userdata)
{
  if (event == cv::EVENT_MBUTTONDOWN)
  {
     mouseClickFlag = 1;
     dX = dX + x - 10;
     dY = dY + y - 10;
     std::cout << "X-Click: " << x << ", Y-Click: " << y << std::endl;
     // move rover to position indicated by click
  }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("nav_state", 1, navCallback);

  ros::Rate loop_rate(10); // 10 Hz

  // initialize GUI 
  std::string mapFile = "/home/halrover/git/kyle/rover_nav_gui_ws/src/nav_gui/screenshots/initFiles/image.png";
  std::string radarFile = "/home/halrover/git/kyle/rover_nav_gui_ws/src/nav_gui/screenshots/radar.png";
  std::string waypointFile = "/home/halrover/git/kyle/rover_nav_gui_ws/src/nav_gui/screenshots/initFiles/waypoints.txt";
  std::string mapInitFile = "/home/halrover/git/kyle/rover_nav_gui_ws/src/nav_gui/screenshots/initFiles/mapInit.txt";
  display myDisplay(mapFile,radarFile,waypointFile,mapInitFile);

  // click to place rover in that location
  cv::setMouseCallback("mainWindow", mouseCallBack, NULL);

  while (ros::ok())
  {
	if (mouseClickFlag)
        {
          mouseClickFlag = 0;
	  cv::Point coords = myDisplay.mRover.getCoordinates();
          std::cout << "Rover Coords: X: " << coords.x << ", Y: " << coords.y << std::endl;
          std::cout << "Click Coords: X: " << dX << ", Y: " << dY << std::endl;
	  dX = dX - coords.x; // update offset values
	  dY = dY - coords.y; // update offset values
	  //myDisplay.init(mapFile,radarFile,waypointFile,mapInitFile,dX,dY);
        }
        myDisplay.updateRover(latitudeVal,longitudeVal,magHeadingVal);
        myDisplay.rotateRadar();
        myDisplay.drawWaypoints();
        myDisplay.drawRover(dX,dY);
        myDisplay.updateDisplay();
        cv::waitKey(1);
	ros::spinOnce(); // catch the most recent message
        loop_rate.sleep();
  }
  ros::spin();

  return 0;
}
