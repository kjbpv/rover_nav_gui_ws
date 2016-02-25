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

void navCallback(const rover_msgs::NavState::ConstPtr& stateMsg)
{
  latitudeVal = stateMsg->position[0];
  longitudeVal = stateMsg->position[1];
  magHeadingVal = stateMsg->phi;

//  ROS_INFO("I heard: [ %f , %f , %f ]", stateMsg->position[0], stateMsg->position[1], stateMsg->phi);
  ROS_INFO("I heard: [ %f , %f , %f ]", latitudeVal, longitudeVal, magHeadingVal);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("nav_state", 1, navCallback);

  ros::Rate loop_rate(10); // 10 Hz

  // initialize GUI 

  std::string mapFile = "/home/kyle/gitMars/ros_nav_gui_ws/src/nav_gui/screenshots/AstronautAssist1.png";
  std::string radarFile = "/home/kyle/gitMars/ros_nav_gui_ws/src/nav_gui/screenshots/radar.png";
  std::string waypointFile = "/home/kyle/gitMars/ros_nav_gui_ws/src/nav_gui/screenshots/waypoints.txt";
  std::string mapInitFile = "/home/kyle/gitMars/ros_nav_gui_ws/src/nav_gui/screenshots/mapInit.txt";
  display myDisplay(mapFile,radarFile,waypointFile,mapInitFile);

  while (ros::ok())
  {
        myDisplay.updateRover(latitudeVal,longitudeVal,magHeadingVal);
        myDisplay.rotateRadar();
        myDisplay.drawWaypoints();
        myDisplay.drawRover();
        myDisplay.updateDisplay();
        cv::waitKey(1);
	ros::spinOnce(); // catch the most recent message
        loop_rate.sleep();
  }
  ros::spin();

  return 0;
}
