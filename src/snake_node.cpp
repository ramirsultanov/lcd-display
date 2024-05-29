#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <iostream>

int main(int argc, char** argv) {
  ros::init(argc, argv, "snake");
  ros::NodeHandle nh;
  ros::Publisher pub = nh.advertise<std_msgs::Int32>("/computer/lcd/cmd", 2);
  std::string buf;
  std::cin >> buf;
  while (buf != "c" && ros::ok()) {
    std_msgs::Int32 msg;
    switch (buf[0]) {
    case 'W':
      msg.data = 1;
      break;
    case 'A':
      msg.data = 2;
      break;
    case 'S':
      msg.data = 3;
      break;
    case 'D':
      msg.data = 4;
      break;
    default:
      break;
    }
    pub.publish(msg);
    std::cin >> buf;
  }
}
