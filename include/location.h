#include <visualization_msgs/Marker.h>
#include <ros/ros.h>
#include "nav_msgs/Odometry.h"
#include <geometry_msgs/Twist.h>
#include <vector>

class Location {
 private:
    ros::NodeHandle n; 
    ros::Publisher  vmarker_pub;
    ros::Subscriber sub;

    float odom_x, odom_y;
    uint8_t count;

    visualization_msgs::Marker marker;

    void odomCallback(const nav_msgs::Odometry::ConstPtr& msg);
    std::vector<double> pickup;
    std::vector<double> dropoff;

    int setMarkerProperties();
    int setDefaultPickAndDropLocations();

 public:
     Location();
    ~Location();
     int visualizeLocation(int argc, char** argv);
     int setPickUpLocation(double x, double y, double z);
     int setDropOffLocation(double x, double y, double z);
};
