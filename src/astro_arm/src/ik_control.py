#!/usr/bin/env python

import rospy,math
from cytpes import c_ushort
from rover_msgs.msg import All, JointAngles
from sensor_msgs.msg import String, Float32MultiArray, UInt16MultiArray
import time
import lib_robotis as lr
from dynamixel_publisher import DynPub
import numpy as np

class IK():
    def __init__(self):
        self.joy = Joy()
        self.cmd = All()
        self.dyn = Float32MultiArray()
        self.dyn_cmd = Float32MultiArray()
        self.ik = UInt16MultiArray()
        self.case = 'Drive'
        self.slow_case = 'Fast'
        self.cam1_sel = 0
        self.cam2_sel = 0

        self.ik.data.append(2046)
        self.ik.data.append(400)
        self.ik.data.append(3050)
        self.ik.data.append(1920)
        self.wristangle1 = 0.0
        self.wristangle2 = 0.0

        self.cmd.lw = 1500
        self.cmd.rw = 1500
        self.cmd.pan = 1500
        self.cmd.tilkt = 1500
        self.cmd.camnum = 0
        self.cmd.q1 = 2046
        self.cmd.q2 = 400
        self.cmd.q3 = 3050
        self.cmd.q4 = 1920
        self.cmd.q5 = 0.0
        self.cmd.q6 = 0.0
        self.cmd.grip = 1000
        self.cmd.chutes = 0
        self.cmd.shovel = 1500
        self.check = True

        self.dyn.data.append(.17645)
        self.dyn.data.append(.8761169)
        self.dyn_cmd.data.append(.17645)
        self.dyn_cmd.data.append(.8761169)
        
        # Publishers and Subscribers
        self.sub1 = rospy.Subscriber('joy', Joy, self.joyCallback)
        self.sub2 = rospy.Subscriber('dynamixel_feedback', Float32MultiArray, self.dynCallback)
        self.sub3 = rospy.Subscriber('SetJointGoal', JointAngles, self.ikCallback)
        self.pub1 = rospy.Publisher('/rover_command', All, queue_size = 1)
        self.pub2 = rospy.Publisher('/mode', String, queue_size = 1)
        self.pub3 = rospy.Publisher('/dynamixel_command', Float32MultiArray, queue_size = 1)
        self.pub4 = rospy.Publisher('/debug_ik',UInt16MultiArray, queue_size = 1)

        # Callbacks
        def ikCallback(self,msg):
            if msg.solved == 1 and self.check == True:
                self.ik.data[0] = msg.q[0]
                self.ik.data[1] = msg.q[1]
                self.ik.data[2] = msg.q[2]
                self.ik.data[3] = msg.q[3]
        
