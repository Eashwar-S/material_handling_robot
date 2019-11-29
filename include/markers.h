#include <visualization_msgs/Marker.h>
#include <ros/ros.h>
#include "nav_msgs/Odometry.h"
#include <geometry_msgs/Twist.h>

class Vmarkers {
 private:
    ros::NodeHandle n; 
    ros::Publisher  vmarker_pub;
    ros::Subscriber sub;

    float odom_x, odom_y;
    uint8_t count;

    visualization_msgs::Marker marker;

    void odomCallback(const nav_msgs::Odometry::ConstPtr& msg);
    int setMarkerProperties();

 public:
     Vmarkers();
    ~Vmarkers();
     int visualizeMarker(int argc, char** argv);
};
