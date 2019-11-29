#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include "nav_msgs/Odometry.h"
#include "markers.h"

int main(int argc, char *argv[]) {
  ros::init(argc,argv,"vmarkers");
  ros::NodeHandle nh;
   
  Location vmarker;
  vmarker.visualizeLocation(argc, argv);

  return 0;
}




 

