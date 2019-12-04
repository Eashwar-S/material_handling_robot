#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "nav_msgs/Odometry.h"
#include "location.hpp"

int main(int argc, char *argv[]) {
  ros::init(argc,argv,"vmarkers");
  ros::NodeHandle nh;
   
  Location vmarker;
  vmarker.visualizeLocations(argc, argv);
  
  ros::spin();
  return 0;
}

