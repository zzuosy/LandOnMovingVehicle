#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <std_msgs/String.h>
#include<iostream>

using namespace std;
int mode = 0;
void keyback(const std_msgs::String::ConstPtr& str)
{
    if(str->data == "d"||str->data=="D"){
		mode = 1;
		}
	std::cout<<"str.data : "<< str->data <<std::endl;

}
int main(int argc, char **argv)
{
    ros::init(argc, argv, "turtlebotctrl_node");
    ros::NodeHandle nh;
    ROS_INFO("start turtlebotctrl node");
    ros::Publisher local_vel_pub = nh.advertise<geometry_msgs::Twist>
        ("/cmd_vel", 10);
    ros::Subscriber key_sub = nh.subscribe("/keys",10,&keyback);
    ros::Rate rate(10.0);
    geometry_msgs::Twist vel;
    vel.linear.x = 0.2;
    vel.angular.z = 0.2;
    while(ros::ok())
    {
        if (mode == 1)
            break;
        local_vel_pub.publish(vel);
        ros::spinOnce();
        rate.sleep();
    }
    
    return 0;

}
