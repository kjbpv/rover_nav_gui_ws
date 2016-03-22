#include "ros/ros.h"
#include "std_msgs/String.h"
#include "rover_msgs/NavState.h"
#include <fstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
  ros::init(argc, argv, "nav_publisher");

  ros::NodeHandle n;

//  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);
  ros::Publisher nav_pub = n.advertise<rover_msgs::NavState>("nav_state", 1);

  ros::Rate loop_rate(50); // publish at 50 Hz
  
  // file containing artificial GPS coordinates
  std::ifstream infile;
  infile.open("/home/kyle/gitMars/ros_nav_gui_ws/src/nav_gui/screenshots/roverData.txt");

  int count = 0;
  while (ros::ok())
  {
    std_msgs::String msg;
    rover_msgs::NavState stateMsg;

    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    if (!infile.fail())
    {
        infile >> stateMsg.position[0];	// latitude
        infile >> stateMsg.position[1];	// longitude
        infile >> stateMsg.phi; 	// course angle?
    }
    else 
    {
    	stateMsg.position[0] = 40.247780; 	// Latitude
    	stateMsg.position[1] = -111.645576; 	// Longitude
	stateMsg.phi = 10;			// course angle?
    }
    stateMsg.position[2] = 0.00459; 	// altitude
    
    stateMsg.Vw = 0;
    stateMsg.theta = 0;
    stateMsg.psi = 0;
    stateMsg.chi = 0;
    stateMsg.p = 0;
    stateMsg.q = 0;
    stateMsg.r = 0;
    stateMsg.Vg = 0;
    stateMsg.base_latitude = 0;
    stateMsg.base_longitude = 0;
    stateMsg.base_altitude = 0;

    ROS_INFO("Latitude: %f, Longitude: %f, Course Angle: %f", stateMsg.position[0], stateMsg.position[1], stateMsg.phi);

    nav_pub.publish(stateMsg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}
