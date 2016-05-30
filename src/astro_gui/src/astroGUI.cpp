#include "ros/ros.h"
#include "opencv2/opencv.hpp"
#include "std_msgs/String.h"
#include "std_msgs/Byte.h"
#include "std_msgs/MultiArrayLayout.h"
#include "std_msgs/MultiArrayDimension.h"
#include "std_msgs/Int32MultiArray.h"
#include "rover_msgs/JointAngles.h"
#include <iostream>
#include <fstream>
#include <ctime>

// define boundaries for GUI and buttons

#define BUTTON_WIDTH 72
#define BUTTON_HEIGHT 68
#define X_BUF_1 22
#define X_BUF_2 52
#define X_BUF_3 50

#define Y_BUF_1 114

#define X_BORDER_LEFT 11
#define X_BUTTON_1_LEFT X_BORDER_LEFT
#define X_BUTTON_2_LEFT X_BORDER_LEFT + BUTTON_WIDTH
#define X_BUTTON_3_LEFT X_BORDER_LEFT + 2*BUTTON_WIDTH + X_BUF_1
#define X_BUTTON_4_LEFT X_BORDER_LEFT + 3*BUTTON_WIDTH + X_BUF_1
#define X_BUTTON_5_LEFT X_BORDER_LEFT + 4*BUTTON_WIDTH + X_BUF_1 + X_BUF_2
#define X_BUTTON_6_LEFT X_BORDER_LEFT + 5*BUTTON_WIDTH + X_BUF_1 + X_BUF_2 + X_BUF_3
#define X_BUTTON_7_LEFT X_BORDER_LEFT + 6*BUTTON_WIDTH + X_BUF_1 + X_BUF_2 + X_BUF_3
#define X_BUTTON_8_LEFT X_BORDER_LEFT + 7*BUTTON_WIDTH + 2*X_BUF_1 + X_BUF_2 + X_BUF_3
#define X_BUTTON_9_LEFT X_BORDER_LEFT + 8*BUTTON_WIDTH + 2*X_BUF_1 + X_BUF_2 + X_BUF_3

#define X_BUTTON_1_RIGHT X_BUTTON_1_LEFT + BUTTON_WIDTH
#define X_BUTTON_2_RIGHT X_BUTTON_2_LEFT + BUTTON_WIDTH
#define X_BUTTON_3_RIGHT X_BUTTON_3_LEFT + BUTTON_WIDTH
#define X_BUTTON_4_RIGHT X_BUTTON_4_LEFT + BUTTON_WIDTH
#define X_BUTTON_5_RIGHT X_BUTTON_5_LEFT + BUTTON_WIDTH
#define X_BUTTON_6_RIGHT X_BUTTON_6_LEFT + BUTTON_WIDTH
#define X_BUTTON_7_RIGHT X_BUTTON_7_LEFT + BUTTON_WIDTH
#define X_BUTTON_8_RIGHT X_BUTTON_8_LEFT + BUTTON_WIDTH
#define X_BUTTON_9_RIGHT X_BUTTON_9_LEFT + BUTTON_WIDTH


#define Y_BORDER_TOP 10
#define Y_BUTTON_1_TOP Y_BORDER_TOP
#define Y_BUTTON_2_TOP Y_BORDER_TOP + BUTTON_HEIGHT
#define Y_BUTTON_3_TOP Y_BORDER_TOP + 2*BUTTON_HEIGHT + Y_BUF_1
#define Y_BUTTON_4_TOP Y_BORDER_TOP + 3*BUTTON_HEIGHT + Y_BUF_1
#define Y_BUTTON_5_TOP Y_BORDER_TOP + 4*BUTTON_HEIGHT + Y_BUF_1

#define Y_BUTTON_1_BOTTOM Y_BUTTON_1_TOP + BUTTON_HEIGHT
#define Y_BUTTON_2_BOTTOM Y_BUTTON_2_TOP + BUTTON_HEIGHT
#define Y_BUTTON_3_BOTTOM Y_BUTTON_3_TOP + BUTTON_HEIGHT
#define Y_BUTTON_4_BOTTOM Y_BUTTON_4_TOP + BUTTON_HEIGHT
#define Y_BUTTON_5_BOTTOM Y_BUTTON_5_TOP + BUTTON_HEIGHT

// define arm states

// ARM_HIGH_FRONT
#define Q1_ARM_HIGH_FRONT 1859
#define Q2_ARM_HIGH_FRONT 968
#define Q3_ARM_HIGH_FRONT 2003
#define Q4_ARM_HIGH_FRONT 1968
#define Q5_ARM_HIGH_FRONT 0
#define Q6_ARM_HIGH_FRONT 0

// ARM_LOW_FRONT
#define Q1_ARM_LOW_FRONT 1946
#define Q2_ARM_LOW_FRONT 3087
#define Q3_ARM_LOW_FRONT 2028
#define Q4_ARM_LOW_FRONT 2053
#define Q5_ARM_LOW_FRONT 0
#define Q6_ARM_LOW_FRONT 0

// ARM_HIGH_CHUTE_1
#define Q1_ARM_HIGH_CHUTE_1 0 
#define Q2_ARM_HIGH_CHUTE_1 697
#define Q3_ARM_HIGH_CHUTE_1 1988
#define Q4_ARM_HIGH_CHUTE_1 2283
#define Q5_ARM_HIGH_CHUTE_1 0
#define Q6_ARM_HIGH_CHUTE_1 0

// ARM_HIGH_CHUTE_2
#define Q1_ARM_HIGH_CHUTE_2 2
#define Q2_ARM_HIGH_CHUTE_2 697
#define Q3_ARM_HIGH_CHUTE_2 1988
#define Q4_ARM_HIGH_CHUTE_2 2283
#define Q5_ARM_HIGH_CHUTE_2 0
#define Q6_ARM_HIGH_CHUTE_2 0

// ARM_HIGH_CHUTE_3
#define Q1_ARM_HIGH_CHUTE_3 290
#define Q2_ARM_HIGH_CHUTE_3 657
#define Q3_ARM_HIGH_CHUTE_3 1938
#define Q4_ARM_HIGH_CHUTE_3 2328
#define Q5_ARM_HIGH_CHUTE_3 0
#define Q6_ARM_HIGH_CHUTE_3 0

// ARM_HIGH_CHUTE_4
#define Q1_ARM_HIGH_CHUTE_4 3551
#define Q2_ARM_HIGH_CHUTE_4 767
#define Q3_ARM_HIGH_CHUTE_4 2313
#define Q4_ARM_HIGH_CHUTE_4 2328
#define Q5_ARM_HIGH_CHUTE_4 0
#define Q6_ARM_HIGH_CHUTE_4 0

// ARM_HIGH_CHUTE_5
#define Q1_ARM_HIGH_CHUTE_5 3374
#define Q2_ARM_HIGH_CHUTE_5 387
#define Q3_ARM_HIGH_CHUTE_5 2533
#define Q4_ARM_HIGH_CHUTE_5 2053
#define Q5_ARM_HIGH_CHUTE_5 0
#define Q6_ARM_HIGH_CHUTE_5 0

// ARM_HIGH_CHUTE_6
#define Q1_ARM_HIGH_CHUTE_6 3173
#define Q2_ARM_HIGH_CHUTE_6 467
#define Q3_ARM_HIGH_CHUTE_6 2213
#define Q4_ARM_HIGH_CHUTE_6 2053
#define Q5_ARM_HIGH_CHUTE_6 0
#define Q6_ARM_HIGH_CHUTE_6 0

// ARM_LOW_CHUTE_1
#define Q1_ARM_LOW_CHUTE_1 0
#define Q2_ARM_LOW_CHUTE_1 298
#define Q3_ARM_LOW_CHUTE_1 3048
#define Q4_ARM_LOW_CHUTE_1 1968
#define Q5_ARM_LOW_CHUTE_1 0
#define Q6_ARM_LOW_CHUTE_1 0

// ARM_LOW_CHUTE_2
#define Q1_ARM_LOW_CHUTE_2 38
#define Q2_ARM_LOW_CHUTE_2 298
#define Q3_ARM_LOW_CHUTE_2 3048
#define Q4_ARM_LOW_CHUTE_2 1968
#define Q5_ARM_LOW_CHUTE_2 0
#define Q6_ARM_LOW_CHUTE_2 0

// ARM_LOW_CHUTE_3
#define Q1_ARM_LOW_CHUTE_3 290
#define Q2_ARM_LOW_CHUTE_3 7
#define Q3_ARM_LOW_CHUTE_3 3413
#define Q4_ARM_LOW_CHUTE_3 2328
#define Q5_ARM_LOW_CHUTE_3 0
#define Q6_ARM_LOW_CHUTE_3 0

// ARM_LOW_CHUTE_4
#define Q1_ARM_LOW_CHUTE_4 3551
#define Q2_ARM_LOW_CHUTE_4 682
#define Q3_ARM_LOW_CHUTE_4 2963
#define Q4_ARM_LOW_CHUTE_4 2328
#define Q5_ARM_LOW_CHUTE_4 0
#define Q6_ARM_LOW_CHUTE_4 0

// ARM_LOW_CHUTE_5
#define Q1_ARM_LOW_CHUTE_5 3374
#define Q2_ARM_LOW_CHUTE_5 242
#define Q3_ARM_LOW_CHUTE_5 3178
#define Q4_ARM_LOW_CHUTE_5 2328
#define Q5_ARM_LOW_CHUTE_5 0
#define Q6_ARM_LOW_CHUTE_5 0

// ARM_LOW_CHUTE_6
#define Q1_ARM_LOW_CHUTE_6 3173
#define Q2_ARM_LOW_CHUTE_6 237
#define Q3_ARM_LOW_CHUTE_6 3088
#define Q4_ARM_LOW_CHUTE_6 2053
#define Q5_ARM_LOW_CHUTE_6 0
#define Q6_ARM_LOW_CHUTE_6 0

// CHUTE_OPEN
#define CHUTE_OPEN_1_BYTE 0b01000001 // bitwise OR with chuteCommand
#define CHUTE_OPEN_2_BYTE 0b01000010 // bitwise OR with chuteCommand
#define CHUTE_OPEN_3_BYTE 0b01000100 // bitwise OR with chuteCommand
#define CHUTE_OPEN_4_BYTE 0b01001000 // bitwise OR with chuteCommand
#define CHUTE_OPEN_5_BYTE 0b01010000 // bitwise OR with chuteCommand
#define CHUTE_OPEN_6_BYTE 0b01100000 // bitwise OR with chuteCommand

#define CHUTE_CLOSE_1_BYTE 0b11111110 // bitwise AND with chuteCommand
#define CHUTE_CLOSE_2_BYTE 0b11111101 // bitwise AND with chuteCommand
#define CHUTE_CLOSE_3_BYTE 0b11111011 // bitwise AND with chuteCommand
#define CHUTE_CLOSE_4_BYTE 0b11110111 // bitwise AND with chuteCommand
#define CHUTE_CLOSE_5_BYTE 0b11101111 // bitwise AND with chuteCommand
#define CHUTE_CLOSE_6_BYTE 0b11011111 // bitwise AND with chuteCommand


// Global variables
enum STATE {ARM_HIGH_FRONT, ARM_LOW_FRONT, ARM_HIGH_CHUTE_1, ARM_HIGH_CHUTE_2, ARM_HIGH_CHUTE_3, ARM_HIGH_CHUTE_4, ARM_HIGH_CHUTE_5, ARM_HIGH_CHUTE_6, ARM_LOW_CHUTE_1, ARM_LOW_CHUTE_2,  ARM_LOW_CHUTE_3, ARM_LOW_CHUTE_4, ARM_LOW_CHUTE_5, ARM_LOW_CHUTE_6, CHUTE_OPEN_1, CHUTE_OPEN_2, CHUTE_OPEN_3, CHUTE_OPEN_4, CHUTE_OPEN_5, CHUTE_OPEN_6, CHUTE_CLOSE_1, CHUTE_CLOSE_2, CHUTE_CLOSE_3, CHUTE_CLOSE_4, CHUTE_CLOSE_5,CHUTE_CLOSE_6};
STATE state;
int mouseClickFlag = 0;

using namespace cv;

void mouseCallback(int event, int x, int y, int flags, void *userdata)
{
    // if left click, do this:
    if (event == EVENT_LBUTTONDOWN)
    {
        mouseClickFlag = 1;
        
        if (x > X_BUTTON_1_LEFT && x < X_BUTTON_1_RIGHT)
        {
            if (y > Y_BUTTON_3_TOP && y < Y_BUTTON_3_BOTTOM) { state = ARM_HIGH_CHUTE_6; }
            else if (y > Y_BUTTON_4_TOP && y < Y_BUTTON_4_BOTTOM) { state = ARM_HIGH_CHUTE_5; }
            else if (y > Y_BUTTON_5_TOP && y < Y_BUTTON_5_BOTTOM) { state = ARM_HIGH_CHUTE_4; }
        }
        else if (x > X_BUTTON_2_LEFT && x < X_BUTTON_2_RIGHT)
        {
            if (y > Y_BUTTON_3_TOP && y < Y_BUTTON_3_BOTTOM) { state = ARM_LOW_CHUTE_6; }
            else if (y > Y_BUTTON_4_TOP && y < Y_BUTTON_4_BOTTOM) { state = ARM_LOW_CHUTE_5; }
            else if (y > Y_BUTTON_5_TOP && y < Y_BUTTON_5_BOTTOM) { state = ARM_LOW_CHUTE_4; }
        }
        else if (x > X_BUTTON_3_LEFT && x < X_BUTTON_3_RIGHT)
        {
            if (y > Y_BUTTON_3_TOP && y < Y_BUTTON_3_BOTTOM) { state = CHUTE_OPEN_6; }
            else if (y > Y_BUTTON_4_TOP && y < Y_BUTTON_4_BOTTOM) { state = CHUTE_OPEN_5; }
            else if (y > Y_BUTTON_5_TOP && y < Y_BUTTON_5_BOTTOM) { state = CHUTE_OPEN_4; }
        }
        else if (x > X_BUTTON_4_LEFT && x < X_BUTTON_4_RIGHT)
        {
            if (y > Y_BUTTON_3_TOP && y < Y_BUTTON_3_BOTTOM) { state = CHUTE_CLOSE_6; }
            else if (y > Y_BUTTON_4_TOP && y < Y_BUTTON_4_BOTTOM) { state = CHUTE_CLOSE_5; }
            else if (y > Y_BUTTON_5_TOP && y < Y_BUTTON_5_BOTTOM) {  state = CHUTE_CLOSE_4; }
        }
        else if (x > X_BUTTON_5_LEFT && x < X_BUTTON_5_RIGHT)
        {
            if (y > Y_BUTTON_1_TOP && y < Y_BUTTON_1_BOTTOM) {  state = ARM_HIGH_FRONT;  }
            else if (y > Y_BUTTON_2_TOP && y < Y_BUTTON_2_BOTTOM) { state = ARM_LOW_FRONT; }
        }
        else if (x > X_BUTTON_6_LEFT && x < X_BUTTON_6_RIGHT)
        {
            if (y > Y_BUTTON_3_TOP && y < Y_BUTTON_3_BOTTOM) {  state = CHUTE_CLOSE_3;  }
            else if (y > Y_BUTTON_4_TOP && y < Y_BUTTON_4_BOTTOM) {  state = CHUTE_CLOSE_2;  }
            else if (y > Y_BUTTON_5_TOP && y < Y_BUTTON_5_BOTTOM) {  state = CHUTE_CLOSE_1;  }
        }
        else if (x > X_BUTTON_7_LEFT && x < X_BUTTON_7_RIGHT)
        {
            if (y > Y_BUTTON_3_TOP && y < Y_BUTTON_3_BOTTOM) {  state = CHUTE_OPEN_3;  }
            else if (y > Y_BUTTON_4_TOP && y < Y_BUTTON_4_BOTTOM) { state = CHUTE_OPEN_2; }
            else if (y > Y_BUTTON_5_TOP && y < Y_BUTTON_5_BOTTOM) { state = CHUTE_OPEN_1; }
        }
        else if (x > X_BUTTON_8_LEFT && x < X_BUTTON_8_RIGHT)
        {
            if (y > Y_BUTTON_3_TOP && y < Y_BUTTON_3_BOTTOM) { state = ARM_LOW_CHUTE_3; }
            else if (y > Y_BUTTON_4_TOP && y < Y_BUTTON_4_BOTTOM) { state = ARM_LOW_CHUTE_2; }
            else if (y > Y_BUTTON_5_TOP && y < Y_BUTTON_5_BOTTOM) { state = ARM_LOW_CHUTE_1; }
        }
        else if (x > X_BUTTON_9_LEFT && x < X_BUTTON_9_RIGHT)
        {
            if (y > Y_BUTTON_3_TOP && y < Y_BUTTON_3_BOTTOM) { state = ARM_HIGH_CHUTE_3; }
            else if (y > Y_BUTTON_4_TOP && y < Y_BUTTON_4_BOTTOM) { state = ARM_HIGH_CHUTE_2; }
            else if (y > Y_BUTTON_5_TOP && y < Y_BUTTON_5_BOTTOM) { state = ARM_HIGH_CHUTE_1; }
        }
    }
}


int main(int argc, char   **argv)
{
	ros::init(argc,argv,"astro_publisher");
	ros::NodeHandle n;
	
	// Publishers
	ros::Publisher astro_arm_pub = n.advertise<rover_msgs::JointAngles>("astro_GUI_arm",1);
	ros::Publisher astro_chutes_pub = n.advertise<std_msgs::Byte>("astro_GUI_chutes",1);
	
	ros::Rate loop_rate(10); // publish at 10 Hz
	
	// messages
	rover_msgs::JointAngles armCommand;
	std_msgs::Byte chuteCommand;
	
	armCommand.q.push_back(0); // turret
	armCommand.q.push_back(1); // shoulder
	armCommand.q.push_back(2); // elbow
	armCommand.q.push_back(3); // wrist
	armCommand.q.push_back(4); // dynamixel 1
	armCommand.q.push_back(5); // dynamixel 2
	armCommand.solved = 1; // solved
	
	// chutecCommand // 0b     0-sciBox 0-enable 0-ch6 0-ch5  0-ch4 0-ch3 0-ch2 0-ch1
	chuteCommand.data = 0b01000000;	
	
	// Load and display GUI
	cv::Mat baseGUI = cv::imread("/home/kyle/gitMars/ros_nav_gui_ws/src/astro_gui/src/gui_images/AstronautAssistGUI.png");
	cv::namedWindow("GUIwindow",CV_WINDOW_AUTOSIZE);
	cv::imshow("GUIwindow",baseGUI);
    Mat GUI;
    baseGUI.copyTo(GUI);
    
    // Load "On" buttons
    Mat ArmHighOn, ArmLowOn, ChuteCloseOn, ChuteOpenOn;
    ArmHighOn = imread("/home/kyle/gitMars/ros_nav_gui_ws/src/astro_gui/src/gui_images/ArmHighOn.png");
    ArmLowOn = imread("/home/kyle/gitMars/ros_nav_gui_ws/src/astro_gui/src/gui_images/ArmLowOn.png");
    ChuteCloseOn = imread("/home/kyle/gitMars/ros_nav_gui_ws/src/astro_gui/src/gui_images/ChuteCloseOn.png");
    ChuteOpenOn = imread("/home/kyle/gitMars/ros_nav_gui_ws/src/astro_gui/src/gui_images/ChuteOpenOn.png");
    Mat ArmHighOff, ArmLowOff, ChuteCloseOff, ChuteOpenOff;
    ArmHighOff = imread("/home/kyle/gitMars/ros_nav_gui_ws/src/astro_gui/src/gui_images/ArmHighOff.png");
    ArmLowOff = imread("/home/kyle/gitMars/ros_nav_gui_ws/src/astro_gui/src/gui_images/ArmLowOff.png");
    ChuteCloseOff = imread("/home/kyle/gitMars/ros_nav_gui_ws/src/astro_gui/src/gui_images/ChuteCloseOff.png");
    ChuteOpenOff = imread("/home/kyle/gitMars/ros_nav_gui_ws/src/astro_gui/src/gui_images/ChuteOpenOff.png");
    
    // define rectangular region to replace activebutton
    Mat activeArmHigh = GUI(Rect(X_BUTTON_1_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
    Mat inactiveArmHigh = GUI(Rect(X_BUTTON_1_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
    Mat activeChuteOpen = GUI(Rect(X_BUTTON_1_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
    Mat inactiveChuteOpen = GUI(Rect(X_BUTTON_1_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
    Mat activeArmLow = GUI(Rect(X_BUTTON_2_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
    Mat inactiveArmLow = GUI(Rect(X_BUTTON_2_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
    Mat activeChuteClosed = GUI(Rect(X_BUTTON_4_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
    Mat inactiveChuteClosed = GUI(Rect(X_BUTTON_4_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
    
    // set Mouse Callback
    setMouseCallback("GUIwindow", mouseCallback, NULL);

	while(ros::ok())
	{
        imshow("GUIwindow", GUI);
        waitKey(1);
		if (mouseClickFlag)
        {
            mouseClickFlag = 0; // reset mouseClickFlag
            
            switch (state) 
            {
                case ARM_HIGH_FRONT:
                    std::cout << "ARM_HIGH_FRONT" << std::endl;
                    
                	armCommand.q[0] = Q1_ARM_HIGH_FRONT; // turret
					armCommand.q[1] = Q2_ARM_HIGH_FRONT; // shoulder
					armCommand.q[2] = Q3_ARM_HIGH_FRONT; // elbow
					armCommand.q[3] = Q4_ARM_HIGH_FRONT; // wrist
					armCommand.q[4] = Q5_ARM_HIGH_FRONT; // dynamixel 1
					armCommand.q[5] = Q6_ARM_HIGH_FRONT; // dynamixel 2
                    
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmHigh = GUI(Rect(X_BUTTON_5_LEFT,Y_BUTTON_1_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmHigh = GUI(Rect(X_BUTTON_5_LEFT,Y_BUTTON_1_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmHighOn.copyTo(activeArmHigh);
                    break;
                case ARM_LOW_FRONT:
                    std::cout << "ARM_LOW_FRONT" << std::endl;
                    
                	armCommand.q[0] = Q1_ARM_LOW_FRONT; // turret
					armCommand.q[1] = Q2_ARM_LOW_FRONT; // shoulder
					armCommand.q[2] = Q3_ARM_LOW_FRONT; // elbow
					armCommand.q[3] = Q4_ARM_LOW_FRONT; // wrist
					armCommand.q[4] = Q5_ARM_LOW_FRONT; // dynamixel 1
					armCommand.q[5] = Q6_ARM_LOW_FRONT; // dynamixel 2
                    
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmLow = GUI(Rect(X_BUTTON_5_LEFT,Y_BUTTON_2_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmLow = GUI(Rect(X_BUTTON_5_LEFT,Y_BUTTON_2_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmLowOn.copyTo(activeArmLow);
                    break;
                case ARM_HIGH_CHUTE_1:
                    std::cout << "ARM_HIGH_CHUTE_1" << std::endl;
                    
                	armCommand.q[0] = Q1_ARM_HIGH_CHUTE_1; // turret
					armCommand.q[1] = Q2_ARM_HIGH_CHUTE_1; // shoulder
					armCommand.q[2] = Q3_ARM_HIGH_CHUTE_1; // elbow
					armCommand.q[3] = Q4_ARM_HIGH_CHUTE_1; // wrist
					armCommand.q[4] = Q5_ARM_HIGH_CHUTE_1; // dynamixel 1
					armCommand.q[5] = Q6_ARM_HIGH_CHUTE_1; // dynamixel 2
                    
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmHigh = GUI(Rect(X_BUTTON_9_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmHigh = GUI(Rect(X_BUTTON_9_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmHighOn.copyTo(activeArmHigh);
                    break;
                case ARM_HIGH_CHUTE_2:
                    std::cout << "ARM_HIGH_CHUTE_2" << std::endl;
                    
                	armCommand.q[0] = Q1_ARM_HIGH_CHUTE_2; // turret
					armCommand.q[1] = Q2_ARM_HIGH_CHUTE_2; // shoulder
					armCommand.q[2] = Q3_ARM_HIGH_CHUTE_2; // elbow
					armCommand.q[3] = Q4_ARM_HIGH_CHUTE_2; // wrist
					armCommand.q[4] = Q5_ARM_HIGH_CHUTE_2; // dynamixel 1
					armCommand.q[5] = Q6_ARM_HIGH_CHUTE_2; // dynamixel 2
                    
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmHigh = GUI(Rect(X_BUTTON_9_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmHigh = GUI(Rect(X_BUTTON_9_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmHighOn.copyTo(activeArmHigh);
                    break;
                case ARM_HIGH_CHUTE_3:
                    std::cout << "ARM_HIGH_CHUTE_3" << std::endl;
                    
                	armCommand.q[0] = Q1_ARM_HIGH_CHUTE_3; // turret
					armCommand.q[1] = Q2_ARM_HIGH_CHUTE_3; // shoulder
					armCommand.q[2] = Q3_ARM_HIGH_CHUTE_3; // elbow
					armCommand.q[3] = Q4_ARM_HIGH_CHUTE_3; // wrist
					armCommand.q[4] = Q5_ARM_HIGH_CHUTE_3; // dynamixel 1
					armCommand.q[5] = Q6_ARM_HIGH_CHUTE_3; // dynamixel 2
                    
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmHigh = GUI(Rect(X_BUTTON_9_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmHigh = GUI(Rect(X_BUTTON_9_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmHighOn.copyTo(activeArmHigh);
                    break;
                case ARM_HIGH_CHUTE_4:
                    std::cout << "ARM_HIGH_CHUTE_4" << std::endl;
                    
                	armCommand.q[0] = Q1_ARM_HIGH_CHUTE_4; // turret
					armCommand.q[1] = Q2_ARM_HIGH_CHUTE_4; // shoulder
					armCommand.q[2] = Q3_ARM_HIGH_CHUTE_4; // elbow
					armCommand.q[3] = Q4_ARM_HIGH_CHUTE_4; // wrist
					armCommand.q[4] = Q5_ARM_HIGH_CHUTE_4; // dynamixel 1
					armCommand.q[5] = Q6_ARM_HIGH_CHUTE_4; // dynamixel 2
                    
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmHigh = GUI(Rect(X_BUTTON_1_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmHigh = GUI(Rect(X_BUTTON_1_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmHighOn.copyTo(activeArmHigh);
                    break;
                case ARM_HIGH_CHUTE_5:
                    std::cout << "ARM_HIGH_CHUTE_5" << std::endl;
                    
                	armCommand.q[0] = Q1_ARM_HIGH_CHUTE_5; // turret
					armCommand.q[1] = Q2_ARM_HIGH_CHUTE_5; // shoulder
					armCommand.q[2] = Q3_ARM_HIGH_CHUTE_5; // elbow
					armCommand.q[3] = Q4_ARM_HIGH_CHUTE_5; // wrist
					armCommand.q[4] = Q5_ARM_HIGH_CHUTE_5; // dynamixel 1
					armCommand.q[5] = Q6_ARM_HIGH_CHUTE_5; // dynamixel 2
                    
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmHigh = GUI(Rect(X_BUTTON_1_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmHigh = GUI(Rect(X_BUTTON_1_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmHighOn.copyTo(activeArmHigh);
                    break;
                case ARM_HIGH_CHUTE_6:
                    std::cout << "ARM_HIGH_CHUTE_6" << std::endl;
                    
                	armCommand.q[0] = Q1_ARM_HIGH_CHUTE_6; // turret
					armCommand.q[1] = Q2_ARM_HIGH_CHUTE_6; // shoulder
					armCommand.q[2] = Q3_ARM_HIGH_CHUTE_6; // elbow
					armCommand.q[3] = Q4_ARM_HIGH_CHUTE_6; // wrist
					armCommand.q[4] = Q5_ARM_HIGH_CHUTE_6; // dynamixel 1
					armCommand.q[5] = Q6_ARM_HIGH_CHUTE_6; // dynamixel 2
                    
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmHigh = GUI(Rect(X_BUTTON_1_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmHigh = GUI(Rect(X_BUTTON_1_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmHighOn.copyTo(activeArmHigh);
                    break;
                case ARM_LOW_CHUTE_1:
                    std::cout << "ARM_LOW_CHUTE_1" << std::endl;
                    
                	armCommand.q[0] = Q1_ARM_LOW_CHUTE_1; // turret
					armCommand.q[1] = Q2_ARM_LOW_CHUTE_1; // shoulder
					armCommand.q[2] = Q3_ARM_LOW_CHUTE_1; // elbow
					armCommand.q[3] = Q4_ARM_LOW_CHUTE_1; // wrist
					armCommand.q[4] = Q5_ARM_LOW_CHUTE_1; // dynamixel 1
					armCommand.q[5] = Q6_ARM_LOW_CHUTE_1; // dynamixel 2
                    
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmLow = GUI(Rect(X_BUTTON_8_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmLow = GUI(Rect(X_BUTTON_8_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmLowOn.copyTo(activeArmLow);
                    break;
                case ARM_LOW_CHUTE_2:
                    std::cout << "ARM_LOW_CHUTE_2" << std::endl;
                    
                	armCommand.q[0] = Q1_ARM_LOW_CHUTE_2; // turret
					armCommand.q[1] = Q2_ARM_LOW_CHUTE_2; // shoulder
					armCommand.q[2] = Q3_ARM_LOW_CHUTE_2; // elbow
					armCommand.q[3] = Q4_ARM_LOW_CHUTE_2; // wrist
					armCommand.q[4] = Q5_ARM_LOW_CHUTE_2; // dynamixel 1
					armCommand.q[5] = Q6_ARM_LOW_CHUTE_2; // dynamixel 2
                    
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmLow = GUI(Rect(X_BUTTON_8_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmLow = GUI(Rect(X_BUTTON_8_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmLowOn.copyTo(activeArmLow);
                    break;
                case ARM_LOW_CHUTE_3:
                    std::cout << "ARM_LOW_CHUTE_3" << std::endl;
                    
                	armCommand.q[0] = Q1_ARM_LOW_CHUTE_3; // turret
					armCommand.q[1] = Q2_ARM_LOW_CHUTE_3; // shoulder
					armCommand.q[2] = Q3_ARM_LOW_CHUTE_3; // elbow
					armCommand.q[3] = Q4_ARM_LOW_CHUTE_3; // wrist
					armCommand.q[4] = Q5_ARM_LOW_CHUTE_3; // dynamixel 1
					armCommand.q[5] = Q6_ARM_LOW_CHUTE_3; // dynamixel 2
                    
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmLow = GUI(Rect(X_BUTTON_8_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmLow = GUI(Rect(X_BUTTON_8_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmLowOn.copyTo(activeArmLow);
                    break;
                case ARM_LOW_CHUTE_4:
                    std::cout << "ARM_LOW_CHUTE_4" << std::endl;
                    
                	armCommand.q[0] = Q1_ARM_LOW_CHUTE_4; // turret
					armCommand.q[1] = Q2_ARM_LOW_CHUTE_4; // shoulder
					armCommand.q[2] = Q3_ARM_LOW_CHUTE_4; // elbow
					armCommand.q[3] = Q4_ARM_LOW_CHUTE_4; // wrist
					armCommand.q[4] = Q5_ARM_LOW_CHUTE_4; // dynamixel 1
					armCommand.q[5] = Q6_ARM_LOW_CHUTE_4; // dynamixel 2
                    
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmLow = GUI(Rect(X_BUTTON_2_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmLow = GUI(Rect(X_BUTTON_2_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmLowOn.copyTo(activeArmLow);
                    break;
                case ARM_LOW_CHUTE_5:
                    std::cout << "ARM_LOW_CHUTE_5" << std::endl;
                    
                	armCommand.q[0] = Q1_ARM_LOW_CHUTE_5; // turret
					armCommand.q[1] = Q2_ARM_LOW_CHUTE_5; // shoulder
					armCommand.q[2] = Q3_ARM_LOW_CHUTE_5; // elbow
					armCommand.q[3] = Q4_ARM_LOW_CHUTE_5; // wrist
					armCommand.q[4] = Q5_ARM_LOW_CHUTE_5; // dynamixel 1
					armCommand.q[5] = Q6_ARM_LOW_CHUTE_5; // dynamixel 2
                    
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmLow = GUI(Rect(X_BUTTON_2_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmLow = GUI(Rect(X_BUTTON_2_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmLowOn.copyTo(activeArmLow);
                    break;
                case ARM_LOW_CHUTE_6:
                    std::cout << "ARM_LOW_CHUTE_6" << std::endl;
                    
                	armCommand.q[0] = Q1_ARM_LOW_CHUTE_6; // turret
					armCommand.q[1] = Q2_ARM_LOW_CHUTE_6; // shoulder
					armCommand.q[2] = Q3_ARM_LOW_CHUTE_6; // elbow
					armCommand.q[3] = Q4_ARM_LOW_CHUTE_6; // wrist
					armCommand.q[4] = Q5_ARM_LOW_CHUTE_6; // dynamixel 1
					armCommand.q[5] = Q6_ARM_LOW_CHUTE_6; // dynamixel 2
                    
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmLow = GUI(Rect(X_BUTTON_2_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmLow = GUI(Rect(X_BUTTON_2_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmLowOn.copyTo(activeArmLow);
                    break;
                case CHUTE_OPEN_1:
                    std::cout << "CHUTE_OPEN_1" << std::endl;
                    
                	chuteCommand.data = chuteCommand.data | CHUTE_OPEN_1_BYTE;
                    
                    inactiveChuteClosed=GUI(Rect(X_BUTTON_6_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeChuteOpen = GUI(Rect(X_BUTTON_7_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ChuteCloseOff.copyTo(inactiveChuteClosed);
                    ChuteOpenOn.copyTo(activeChuteOpen);
                    break;
                case CHUTE_OPEN_2:
                    std::cout << "CHUTE_OPEN_2" << std::endl;
                    
                	chuteCommand.data = chuteCommand.data | CHUTE_OPEN_2_BYTE;
                    
                    inactiveChuteClosed=GUI(Rect(X_BUTTON_6_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeChuteOpen = GUI(Rect(X_BUTTON_7_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ChuteCloseOff.copyTo(inactiveChuteClosed);
                    ChuteOpenOn.copyTo(activeChuteOpen);
                    break;
                case CHUTE_OPEN_3:
                    std::cout << "CHUTE_OPEN_3" << std::endl;
                    
                	chuteCommand.data = chuteCommand.data | CHUTE_OPEN_3_BYTE;
                    
                    inactiveChuteClosed=GUI(Rect(X_BUTTON_6_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeChuteOpen = GUI(Rect(X_BUTTON_7_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ChuteCloseOff.copyTo(inactiveChuteClosed);
                    ChuteOpenOn.copyTo(activeChuteOpen);
                    break;
                case CHUTE_OPEN_4:
                    std::cout << "CHUTE_OPEN_4" << std::endl;
                    
                	chuteCommand.data = chuteCommand.data | CHUTE_OPEN_4_BYTE;
                    
                    inactiveChuteClosed=GUI(Rect(X_BUTTON_4_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeChuteOpen = GUI(Rect(X_BUTTON_3_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ChuteCloseOff.copyTo(inactiveChuteClosed);
                    ChuteOpenOn.copyTo(activeChuteOpen);
                    break;
                case CHUTE_OPEN_5:
                    std::cout << "CHUTE_OPEN_5" << std::endl;
                    
                	chuteCommand.data = chuteCommand.data | CHUTE_OPEN_5_BYTE;
                    
                    inactiveChuteClosed=GUI(Rect(X_BUTTON_4_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeChuteOpen = GUI(Rect(X_BUTTON_3_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ChuteCloseOff.copyTo(inactiveChuteClosed);
                    ChuteOpenOn.copyTo(activeChuteOpen);
                    break;
                case CHUTE_OPEN_6:
                    std::cout << "CHUTE_OPEN_6" << std::endl;
                    
                	chuteCommand.data = chuteCommand.data | CHUTE_OPEN_6_BYTE;
                    
                    inactiveChuteClosed=GUI(Rect(X_BUTTON_4_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeChuteOpen = GUI(Rect(X_BUTTON_3_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ChuteCloseOff.copyTo(inactiveChuteClosed);
                    ChuteOpenOn.copyTo(activeChuteOpen);
                    break;
                case CHUTE_CLOSE_1:
                    std::cout << "CHUTE_CLOSE_1" << std::endl;
                    
                	chuteCommand.data = chuteCommand.data & CHUTE_CLOSE_1_BYTE;
                    
                    activeChuteClosed=GUI(Rect(X_BUTTON_6_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    inactiveChuteOpen = GUI(Rect(X_BUTTON_7_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ChuteCloseOn.copyTo(activeChuteClosed);
                    ChuteOpenOff.copyTo(inactiveChuteOpen);
                    break;
                case CHUTE_CLOSE_2:
                    std::cout << "CHUTE_CLOSE_2" << std::endl;
                    
                	chuteCommand.data = chuteCommand.data & CHUTE_CLOSE_2_BYTE;
                    
                    activeChuteClosed=GUI(Rect(X_BUTTON_6_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    inactiveChuteOpen = GUI(Rect(X_BUTTON_7_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ChuteCloseOn.copyTo(activeChuteClosed);
                    ChuteOpenOff.copyTo(inactiveChuteOpen);
                    break;
                case CHUTE_CLOSE_3:
                    std::cout << "CHUTE_CLOSE_3" << std::endl;
                    
                	chuteCommand.data = chuteCommand.data & CHUTE_CLOSE_3_BYTE;
                    
                    activeChuteClosed=GUI(Rect(X_BUTTON_6_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    inactiveChuteOpen = GUI(Rect(X_BUTTON_7_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ChuteCloseOn.copyTo(activeChuteClosed);
                    ChuteOpenOff.copyTo(inactiveChuteOpen);
                    break;
                case CHUTE_CLOSE_4:
                    
                	chuteCommand.data = chuteCommand.data & CHUTE_CLOSE_4_BYTE;
                    
                    activeChuteClosed=GUI(Rect(X_BUTTON_4_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    inactiveChuteOpen = GUI(Rect(X_BUTTON_3_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ChuteCloseOn.copyTo(activeChuteClosed);
                    ChuteOpenOff.copyTo(inactiveChuteOpen);
                    break;
                case CHUTE_CLOSE_5:
                    std::cout << "CHUTE_CLOSE_5" << std::endl;
                    
                	chuteCommand.data = chuteCommand.data & CHUTE_CLOSE_5_BYTE;
                    
                    activeChuteClosed=GUI(Rect(X_BUTTON_4_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    inactiveChuteOpen = GUI(Rect(X_BUTTON_3_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ChuteCloseOn.copyTo(activeChuteClosed);
                    ChuteOpenOff.copyTo(inactiveChuteOpen);
                    break;
                case CHUTE_CLOSE_6:
                    std::cout << "CHUTE_CLOSE_6" << std::endl;
                    
                	chuteCommand.data = chuteCommand.data & CHUTE_CLOSE_6_BYTE;
                    
                    activeChuteClosed=GUI(Rect(X_BUTTON_4_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    inactiveChuteOpen = GUI(Rect(X_BUTTON_3_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ChuteCloseOn.copyTo(activeChuteClosed);
                    ChuteOpenOff.copyTo(inactiveChuteOpen);
                    break;
                default:
                    break;
                    
            }
            
            astro_arm_pub.publish(armCommand);
            astro_chutes_pub.publish(chuteCommand);
        }
        
		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}
