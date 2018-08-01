#include "ros/ros.h" 
  
 //    ros/ros.h是一个实用的头文件，它引用了ROS系统中大部分常用的头文件，使用它会使得编程很简便。

#include "std_msgs/String.h" 
     //std_msgs/String 消息, 它存放在std_msgs    package里，是由String.msg文件自动生成的头文件。

#include <sstream>

int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "talker");

  
  ros::NodeHandle n;

  
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

  ros::Rate loop_rate(10);

  
  int count = 0;
  while (ros::ok())
  {
   
    std_msgs::String msg;

    std::stringstream ss;
    ss << "hello world " << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }


  return 0;
}