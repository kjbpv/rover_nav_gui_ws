#include "ros/ros.h"
#include "opencv2/opencv.hpp"
#include "std_msgs/String.h"
#include <iostream>

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;

  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
  std::cout <<"Hello World" << std::endl;
  cv::Mat background(660,1280,CV_8UC3,cv::Scalar(80,80,80)); // Gray background
  cv::namedWindow("mainWindow",CV_WINDOW_AUTOSIZE);
  cv::imshow("mainWindow",background);
  cv::waitKey(30);

  ros::spin();

  return 0;
}