#include "ros/ros.h"
#include "std_msgs/String.h"

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
void chatterCallback(const std_msgs::String::ConstPtr& msg) //这是一个回调函数，当消息到达chatter topic的时候就会被调用。
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
  
   */
  ros::init(argc, argv, "listener"); 

 
  ros::NodeHandle n;

  
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

  
  ros::spin();//ros::spin()进入自循环，可以尽可能快的调用消息回调函数。

  return 0;
}