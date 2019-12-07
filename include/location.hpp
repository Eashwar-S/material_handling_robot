#include <visualization_msgs/Marker.h>
#include <ros/ros.h>
#include "nav_msgs/Odometry.h"
#include <geometry_msgs/Twist.h>
#include "Stations.hpp"
#include <vector>
#include <bitset>

class Location
{
private:
   ros::NodeHandle n;
   ros::Publisher vmarker_pub;
   ros::Subscriber sub;
   float odom_x, odom_y;

   Stations stations;
   std::vector<visualization_msgs::Marker> stationMarkers;

   void odomCallback(const nav_msgs::Odometry::ConstPtr &msg);

public:
   Location();
   ~Location();
   int visualizeLocations(int argc, char **argv);
   int displayStations();
   int publishStationLocations();
   bool isNearTarget(const visualization_msgs::Marker &target);
   int displayTargetLocation(visualization_msgs::Marker &dropOff);
   int setMarkerProperties(int color, int id, Position p, visualization_msgs::Marker &m);
};
