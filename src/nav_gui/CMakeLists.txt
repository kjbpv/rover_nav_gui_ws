cmake_minimum_required(VERSION 2.8.3)
project(nav_gui)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  genmsg
  std_msgs
  sensor_msgs
  geometry_msgs
  rover_msgs
)

find_package(OpenCV REQUIRED)

add_message_files(
  FILES
  Num.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES nav_gui
#  CATKIN_DEPENDS message_runtime roscpp std_msgs
  DEPENDS system_lib
)

#include_directories(
#  ${catkin_INCLUDE_DIRS}
#)

include_directories(include ${catkin_INCLUDE_DIRS})
include_directories(SYSTEM ${OpenCV_INCLUDE_DIRS})

add_executable(nav_publisher src/nav_publisher.cpp)
target_link_libraries(nav_publisher ${catkin_LIBRARIES})
add_dependencies(nav_publisher nav_gui_generate_messages_cpp)

add_executable(nav_subscriber src/nav_subscriber.cpp src/screenshot.cpp src/rover.cpp src/waypoint.cpp src/display.cpp src/patch.cpp)
target_link_libraries(nav_subscriber ${catkin_LIBRARIES} ${OpenCV_LIBRARIES})
add_dependencies(nav_subscriber nav_gui_generate_messages_cpp)

