#include "ros/ros.h"
#include "opencv2/opencv.hpp"
#include "std_msgs/String.h"
#include "rover_msgs/JointAngles.h"
#include <iostream>
#include <fstream>
#include <ctime>

// define boundaries
#define SCALE_FACTOR 0.5

#define BUTTON_WIDTH 72 * SCALE_FACTOR
#define BUTTON_HEIGHT 68 * SCALE_FACTOR
#define X_BUF_1 22 * SCALE_FACTOR
#define X_BUF_2 52 * SCALE_FACTOR
#define X_BUF_3 50 * SCALE_FACTOR

#define Y_BUF_1 114 * SCALE_FACTOR

#define X_BORDER_LEFT (11) * SCALE_FACTOR
#define X_BUTTON_1_LEFT (X_BORDER_LEFT)
#define X_BUTTON_2_LEFT (X_BORDER_LEFT + BUTTON_WIDTH)
#define X_BUTTON_3_LEFT (X_BORDER_LEFT + 2*BUTTON_WIDTH + X_BUF_1)
#define X_BUTTON_4_LEFT (X_BORDER_LEFT + 3*BUTTON_WIDTH + X_BUF_1)
#define X_BUTTON_5_LEFT (X_BORDER_LEFT + 4*BUTTON_WIDTH + X_BUF_1 + X_BUF_2)
#define X_BUTTON_6_LEFT (X_BORDER_LEFT + 5*BUTTON_WIDTH + X_BUF_1 + X_BUF_2 + X_BUF_3)
#define X_BUTTON_7_LEFT (X_BORDER_LEFT + 6*BUTTON_WIDTH + X_BUF_1 + X_BUF_2 + X_BUF_3)
#define X_BUTTON_8_LEFT (X_BORDER_LEFT + 7*BUTTON_WIDTH + 2*X_BUF_1 + X_BUF_2 + X_BUF_3)
#define X_BUTTON_9_LEFT (X_BORDER_LEFT + 8*BUTTON_WIDTH + 2*X_BUF_1 + X_BUF_2 + X_BUF_3)

#define X_BUTTON_1_RIGHT (X_BUTTON_1_LEFT + BUTTON_WIDTH)
#define X_BUTTON_2_RIGHT (X_BUTTON_2_LEFT + BUTTON_WIDTH)
#define X_BUTTON_3_RIGHT (X_BUTTON_3_LEFT + BUTTON_WIDTH)
#define X_BUTTON_4_RIGHT (X_BUTTON_4_LEFT + BUTTON_WIDTH)
#define X_BUTTON_5_RIGHT (X_BUTTON_5_LEFT + BUTTON_WIDTH)
#define X_BUTTON_6_RIGHT (X_BUTTON_6_LEFT + BUTTON_WIDTH)
#define X_BUTTON_7_RIGHT (X_BUTTON_7_LEFT + BUTTON_WIDTH)
#define X_BUTTON_8_RIGHT (X_BUTTON_8_LEFT + BUTTON_WIDTH)
#define X_BUTTON_9_RIGHT (X_BUTTON_9_LEFT + BUTTON_WIDTH)


#define Y_BORDER_TOP (10) * SCALE_FACTOR
#define Y_BUTTON_1_TOP (Y_BORDER_TOP)
#define Y_BUTTON_2_TOP (Y_BORDER_TOP + BUTTON_HEIGHT)
#define Y_BUTTON_3_TOP (Y_BORDER_TOP + 2*BUTTON_HEIGHT + Y_BUF_1)
#define Y_BUTTON_4_TOP (Y_BORDER_TOP + 3*BUTTON_HEIGHT + Y_BUF_1)
#define Y_BUTTON_5_TOP (Y_BORDER_TOP + 4*BUTTON_HEIGHT + Y_BUF_1)

#define Y_BUTTON_1_BOTTOM (Y_BUTTON_1_TOP + BUTTON_HEIGHT)
#define Y_BUTTON_2_BOTTOM (Y_BUTTON_2_TOP + BUTTON_HEIGHT)
#define Y_BUTTON_3_BOTTOM (Y_BUTTON_3_TOP + BUTTON_HEIGHT)
#define Y_BUTTON_4_BOTTOM (Y_BUTTON_4_TOP + BUTTON_HEIGHT)
#define Y_BUTTON_5_BOTTOM (Y_BUTTON_5_TOP + BUTTON_HEIGHT)

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
	ros::Publisher astro_chutes_pub = n.advertise<rover_msgs::JointAngles>("astro_GUI_chutes",1);
	
	ros::Rate loop_rate(10); // publish at 10 Hz
	
	// Load and display GUI
	cv::Mat baseGUI = cv::imread("/home/halrover/git/kyle/rover_nav_gui_ws/src/astro_gui/src/gui_images/small/AstronautAssistGUI.png");
	cv::namedWindow("GUIwindow",CV_WINDOW_AUTOSIZE);
	cv::imshow("GUIwindow",baseGUI);
//	cv::pyrDown(baseGUI,baseGUI);
    Mat GUI;
    baseGUI.copyTo(GUI);
    
    // Load "On" buttons
    Mat ArmHighOn, ArmLowOn, ChuteCloseOn, ChuteOpenOn;
    ArmHighOn = imread("/home/halrover/git/kyle/rover_nav_gui_ws/src/astro_gui/src/gui_images/small/ArmHighOn.png");
    ArmLowOn = imread("/home/halrover/git/kyle/rover_nav_gui_ws/src/astro_gui/src/gui_images/small/ArmLowOn.png");
    ChuteCloseOn = imread("/home/halrover/git/kyle/rover_nav_gui_ws/src/astro_gui/src/gui_images/small/ChuteCloseOn.png");
    ChuteOpenOn = imread("/home/halrover/git/kyle/rover_nav_gui_ws/src/astro_gui/src/gui_images/small/ChuteOpenOn.png");
    Mat ArmHighOff, ArmLowOff, ChuteCloseOff, ChuteOpenOff;
    ArmHighOff = imread("/home/halrover/git/kyle/rover_nav_gui_ws/src/astro_gui/src/gui_images/small/ArmHighOff.png");
    ArmLowOff = imread("/home/halrover/git/kyle/rover_nav_gui_ws/src/astro_gui/src/gui_images/small/ArmLowOff.png");
    ChuteCloseOff = imread("/home/halrover/git/kyle/rover_nav_gui_ws/src/astro_gui/src/gui_images/small/ChuteCloseOff.png");
    ChuteOpenOff = imread("/home/halrover/git/kyle/rover_nav_gui_ws/src/astro_gui/src/gui_images/small/ChuteOpenOff.png");
//    pyrDown(ArmHighOn,ArmHighOn);
//    pyrDown(ArmHighOff,ArmHighOff);
//    pyrDown(ArmLowOn,ArmLowOn);
//    pyrDown(ArmLowOff,ArmLowOff);
//    pyrDown(ChuteCloseOn,ChuteCloseOn);
//    pyrDown(ChuteCloseOff,ChuteCloseOff);
//    pyrDown(ChuteOpenOn,ChuteOpenOn);
//    pyrDown(ChuteOpenOff,ChuteOpenOff);
    
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
            
            switch (state) {
                case ARM_HIGH_FRONT:
                    std::cout << "ARM_HIGH_FRONT" << std::endl;
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmHigh = GUI(Rect(X_BUTTON_5_LEFT,Y_BUTTON_1_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmHigh = GUI(Rect(X_BUTTON_5_LEFT,Y_BUTTON_1_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmHighOn.copyTo(activeArmHigh);
                    break;
                case ARM_LOW_FRONT:
                    std::cout << "ARM_LOW_FRONT" << std::endl;
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmLow = GUI(Rect(X_BUTTON_5_LEFT,Y_BUTTON_2_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmLow = GUI(Rect(X_BUTTON_5_LEFT,Y_BUTTON_2_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmLowOn.copyTo(activeArmLow);
                    break;
                case ARM_HIGH_CHUTE_1:
                    std::cout << "ARM_HIGH_CHUTE_1" << std::endl;
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmHigh = GUI(Rect(X_BUTTON_9_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmHigh = GUI(Rect(X_BUTTON_9_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmHighOn.copyTo(activeArmHigh);
                    break;
                case ARM_HIGH_CHUTE_2:
                    std::cout << "ARM_HIGH_CHUTE_2" << std::endl;
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmHigh = GUI(Rect(X_BUTTON_9_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmHigh = GUI(Rect(X_BUTTON_9_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmHighOn.copyTo(activeArmHigh);
                    break;
                case ARM_HIGH_CHUTE_3:
                    std::cout << "ARM_HIGH_CHUTE_3" << std::endl;
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmHigh = GUI(Rect(X_BUTTON_9_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmHigh = GUI(Rect(X_BUTTON_9_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmHighOn.copyTo(activeArmHigh);
                    break;
                case ARM_HIGH_CHUTE_4:
                    std::cout << "ARM_HIGH_CHUTE_4" << std::endl;
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmHigh = GUI(Rect(X_BUTTON_1_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmHigh = GUI(Rect(X_BUTTON_1_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmHighOn.copyTo(activeArmHigh);
                    break;
                case ARM_HIGH_CHUTE_5:
                    std::cout << "ARM_HIGH_CHUTE_5" << std::endl;
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmHigh = GUI(Rect(X_BUTTON_1_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmHigh = GUI(Rect(X_BUTTON_1_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmHighOn.copyTo(activeArmHigh);
                    break;
                case ARM_HIGH_CHUTE_6:
                    std::cout << "ARM_HIGH_CHUTE_6" << std::endl;
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmHigh = GUI(Rect(X_BUTTON_1_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmHigh = GUI(Rect(X_BUTTON_1_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmHighOn.copyTo(activeArmHigh);
                    break;
                case ARM_LOW_CHUTE_1:
                    std::cout << "ARM_LOW_CHUTE_1" << std::endl;
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmLow = GUI(Rect(X_BUTTON_8_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmLow = GUI(Rect(X_BUTTON_8_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmLowOn.copyTo(activeArmLow);
                    break;
                case ARM_LOW_CHUTE_2:
                    std::cout << "ARM_LOW_CHUTE_2" << std::endl;
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmLow = GUI(Rect(X_BUTTON_8_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmLow = GUI(Rect(X_BUTTON_8_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmLowOn.copyTo(activeArmLow);
                    break;
                case ARM_LOW_CHUTE_3:
                    std::cout << "ARM_LOW_CHUTE_3" << std::endl;
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmLow = GUI(Rect(X_BUTTON_8_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmLow = GUI(Rect(X_BUTTON_8_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmLowOn.copyTo(activeArmLow);
                    break;
                case ARM_LOW_CHUTE_4:
                    std::cout << "ARM_LOW_CHUTE_4" << std::endl;
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmLow = GUI(Rect(X_BUTTON_2_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmLow = GUI(Rect(X_BUTTON_2_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmLowOn.copyTo(activeArmLow);
                    break;
                case ARM_LOW_CHUTE_5:
                    std::cout << "ARM_LOW_CHUTE_5" << std::endl;
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmLow = GUI(Rect(X_BUTTON_2_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmLow = GUI(Rect(X_BUTTON_2_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmLowOn.copyTo(activeArmLow);
                    break;
                case ARM_LOW_CHUTE_6:
                    std::cout << "ARM_LOW_CHUTE_6" << std::endl;
                    ArmHighOff.copyTo(inactiveArmHigh);
                    ArmLowOff.copyTo(inactiveArmLow);
                    inactiveArmLow = GUI(Rect(X_BUTTON_2_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeArmLow = GUI(Rect(X_BUTTON_2_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ArmLowOn.copyTo(activeArmLow);
                    break;
                case CHUTE_OPEN_1:
                    std::cout << "CHUTE_OPEN_1" << std::endl;
                    inactiveChuteClosed=GUI(Rect(X_BUTTON_6_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeChuteOpen = GUI(Rect(X_BUTTON_7_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ChuteCloseOff.copyTo(inactiveChuteClosed);
                    ChuteOpenOn.copyTo(activeChuteOpen);
                    break;
                case CHUTE_OPEN_2:
                    std::cout << "CHUTE_OPEN_2" << std::endl;
                    inactiveChuteClosed=GUI(Rect(X_BUTTON_6_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeChuteOpen = GUI(Rect(X_BUTTON_7_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ChuteCloseOff.copyTo(inactiveChuteClosed);
                    ChuteOpenOn.copyTo(activeChuteOpen);
                    break;
                case CHUTE_OPEN_3:
                    std::cout << "CHUTE_OPEN_3" << std::endl;
                    inactiveChuteClosed=GUI(Rect(X_BUTTON_6_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeChuteOpen = GUI(Rect(X_BUTTON_7_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ChuteCloseOff.copyTo(inactiveChuteClosed);
                    ChuteOpenOn.copyTo(activeChuteOpen);
                    break;
                case CHUTE_OPEN_4:
                    std::cout << "CHUTE_OPEN_4" << std::endl;
                    inactiveChuteClosed=GUI(Rect(X_BUTTON_4_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeChuteOpen = GUI(Rect(X_BUTTON_3_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ChuteCloseOff.copyTo(inactiveChuteClosed);
                    ChuteOpenOn.copyTo(activeChuteOpen);
                    break;
                case CHUTE_OPEN_5:
                    std::cout << "CHUTE_OPEN_5" << std::endl;
                    inactiveChuteClosed=GUI(Rect(X_BUTTON_4_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeChuteOpen = GUI(Rect(X_BUTTON_3_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ChuteCloseOff.copyTo(inactiveChuteClosed);
                    ChuteOpenOn.copyTo(activeChuteOpen);
                    break;
                case CHUTE_OPEN_6:
                    std::cout << "CHUTE_OPEN_6" << std::endl;
                    inactiveChuteClosed=GUI(Rect(X_BUTTON_4_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    activeChuteOpen = GUI(Rect(X_BUTTON_3_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ChuteCloseOff.copyTo(inactiveChuteClosed);
                    ChuteOpenOn.copyTo(activeChuteOpen);
                    break;
                case CHUTE_CLOSE_1:
                    std::cout << "CHUTE_CLOSE_1" << std::endl;
                    activeChuteClosed=GUI(Rect(X_BUTTON_6_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    inactiveChuteOpen = GUI(Rect(X_BUTTON_7_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ChuteCloseOn.copyTo(activeChuteClosed);
                    ChuteOpenOff.copyTo(inactiveChuteOpen);
                    break;
                case CHUTE_CLOSE_2:
                    std::cout << "CHUTE_CLOSE_2" << std::endl;
                    activeChuteClosed=GUI(Rect(X_BUTTON_6_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    inactiveChuteOpen = GUI(Rect(X_BUTTON_7_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ChuteCloseOn.copyTo(activeChuteClosed);
                    ChuteOpenOff.copyTo(inactiveChuteOpen);
                    break;
                case CHUTE_CLOSE_3:
                    std::cout << "CHUTE_CLOSE_3" << std::endl;
                    activeChuteClosed=GUI(Rect(X_BUTTON_6_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    inactiveChuteOpen = GUI(Rect(X_BUTTON_7_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ChuteCloseOn.copyTo(activeChuteClosed);
                    ChuteOpenOff.copyTo(inactiveChuteOpen);
                    break;
                case CHUTE_CLOSE_4:
                    std::cout << "CHUTE_CLOSE_4" << std::endl;
                    activeChuteClosed=GUI(Rect(X_BUTTON_4_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    inactiveChuteOpen = GUI(Rect(X_BUTTON_3_LEFT,Y_BUTTON_5_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ChuteCloseOn.copyTo(activeChuteClosed);
                    ChuteOpenOff.copyTo(inactiveChuteOpen);
                    break;
                case CHUTE_CLOSE_5:
                    std::cout << "CHUTE_CLOSE_5" << std::endl;
                    activeChuteClosed=GUI(Rect(X_BUTTON_4_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    inactiveChuteOpen = GUI(Rect(X_BUTTON_3_LEFT,Y_BUTTON_4_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ChuteCloseOn.copyTo(activeChuteClosed);
                    ChuteOpenOff.copyTo(inactiveChuteOpen);
                    break;
                case CHUTE_CLOSE_6:
                    std::cout << "CHUTE_CLOSE_6" << std::endl;
                    activeChuteClosed=GUI(Rect(X_BUTTON_4_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    inactiveChuteOpen = GUI(Rect(X_BUTTON_3_LEFT,Y_BUTTON_3_TOP,BUTTON_WIDTH,BUTTON_HEIGHT));
                    ChuteCloseOn.copyTo(activeChuteClosed);
                    ChuteOpenOff.copyTo(inactiveChuteOpen);
                    break;
                default:
                    break;
                    
            }
        }
		ros::spinOnce();
		loop_rate.sleep();
	}

	return 0;
}
