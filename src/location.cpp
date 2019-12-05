#include "location.hpp"


void Location::odomCallback(const nav_msgs::Odometry::ConstPtr& msg) {
  odom_x = msg->pose.pose.position.x;
  odom_y = msg->pose.pose.position.y;
}


Location::Location() {
  odom_x= 0;
  odom_y= 0;
  //uint8_t count= 0;
  sub = n.subscribe("odom", 1000, &Location::odomCallback,this);
  vmarker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
  
  displayStations();
}


int Location::displayStations() {
  std::vector<Position> vec = stations.getStations();
  int count = 1;
  for (Position p: vec) {
     visualization_msgs::Marker m;
     setMarkerProperties(count,count-1,p,m);
     count++;
     stationMarkers.push_back(m);
  }
}



int Location::setMarkerProperties(int color, int id, Position p, visualization_msgs::Marker& m) {
     
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.

    m.header.frame_id = "/map";
    m.header.stamp = ros::Time::now();
   
     //Set the namespace and id for this marker.  This serves to create a unique ID
     //Any marker sent with the same namespace and id will overwrite the old one
    m.ns = "vmarkers";
    m.id = id;
   
     //Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER

    m.type = visualization_msgs::Marker::CUBE;
    m.action = visualization_msgs::Marker::ADD;
    m.pose.position.x = p.getX();
    m.pose.position.y = p.getY(); 
    m.pose.position.z = 0; 
    m.pose.orientation.w = 1.0;

    m.scale.x = 0.3;
    m.scale.y = 0.3;
    m.scale.z = 0.3;

     //Set the color -- be sure to set alpha to something non-zero!
    std::bitset<8> binary(color);
        
    m.color.r = binary[0];
    m.color.g = binary[1];
    m.color.b = binary[2];
    m.color.a = 1.0;

    m.lifetime = ros::Duration();
    return 0;
}


int Location::publishStationLocations() {
  for (visualization_msgs::Marker mac:stationMarkers) {
    vmarker_pub.publish(mac);
  }
}


int Location::displayTargetLocation(visualization_msgs::Marker  &target) {
   target.type = visualization_msgs::Marker::SPHERE;
   target.action = visualization_msgs::Marker::ADD;

   return 0;
}

bool Location::isNearTarget(const visualization_msgs::Marker &target) {
    float actual_dis_x, actual_dis_y;
    float threshold = 0.3;

    actual_dis_x = fabs(target.pose.position.x - odom_x);
    actual_dis_y = fabs(target.pose.position.y - odom_y);


    return (actual_dis_x<threshold) && (actual_dis_y < threshold);
}


int Location::visualizeLocations(int argc, char** argv) {
  ros::Rate r(20);
  bool objectHasBeenPicked = false;
  while (ros::ok()) {
      if (!objectHasBeenPicked) {
        if (isNearTarget(stationMarkers[1])) {
           displayTargetLocation(stationMarkers[1]);
           objectHasBeenPicked = true;
          }
          //if (true)
           //displayTargetLocation(stationMarkers[1]);
       }

      else {
        if(isNearTarget(stationMarkers[2]))
          displayTargetLocation(stationMarkers[2]);

        ros::Duration(5.0).sleep();
      }

      publishStationLocations();
      ros::spinOnce();
      r.sleep();
    }
   return 0;
}


Location::~Location() {}

