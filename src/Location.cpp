/******************************************************************************
 * MIT License
 *
 * Copyright (c) 2019 Akwasi A Obeng and Eashwar Sathyamurthy
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

/**
 * @file Location.cpp
 *
 * @author Akwasi A Obeng(Driver)  Eashwar Sathyamurthy(Navigator)
 *
 * @brief cpp program for definition and implementation of the methods of
 *        Location class
 *
 * @version 1
 *
 * @date 2019-12-06
 *
 * This program implements the methods of the
 * Location class from Location.hpp header file
 *
 */
#include "Location.hpp"

void Location::odomCallback(const nav_msgs::Odometry::ConstPtr& msg) {
  odom_x = msg->pose.pose.position.x;
  odom_y = msg->pose.pose.position.y;
}

Location::Location() {
  odom_x = 0;
  odom_y = 0;
  sub = n.subscribe("odom", 1000, &Location::odomCallback, this);
  vmarker_pub = n.advertise < visualization_msgs::Marker
      > ("visualization_marker", 10);

  displayStations();
}

int Location::displayStations() {
  std::vector < Position > vec = stations.getStations();
  int count = 1;
  for (Position p : vec) {
    visualization_msgs::Marker m;
    setMarkerProperties(count, count - 1, p, m);
    count++;
    stationMarkers.push_back(m);
  }
  return 0;
}

int Location::setMarkerProperties(int color, int id, Position p,
                                  visualization_msgs::Marker& m) {
  // Setting the frame ID and timestamp.

  m.header.frame_id = "/map";
  m.header.stamp = ros::Time::now();

  // Set the namespace and id for this marker. This serves to create a unique ID
  // Any marker sent with the same namespace and id will overwrite the old one
  m.ns = "vmarkers";
  m.id = id;
  /// Setting the marker type.
  m.type = visualization_msgs::Marker::CUBE;
  m.action = visualization_msgs::Marker::ADD;
  /// Setting the marker position and orientation.
  m.pose.position.x = p.getX();
  m.pose.position.y = p.getY();
  m.pose.position.z = 0;
  m.pose.orientation.w = 1.0;

  m.scale.x = 0.3;
  m.scale.y = 0.3;
  m.scale.z = 0.3;

  /// Converting integer color into binary form
  std::bitset < 8 > binary(color);

  m.color.r = binary[0];
  m.color.g = binary[1];
  m.color.b = binary[2];
  m.color.a = 1.0;

  m.lifetime = ros::Duration();
  return 0;
}

int Location::publishStationLocations() {
  for (visualization_msgs::Marker mac : stationMarkers) {
    vmarker_pub.publish(mac);
  }
  return 0;
}

int Location::displayTargetLocation(visualization_msgs::Marker &target) {
  /// Changing marker shape to sphere
  target.type = visualization_msgs::Marker::SPHERE;
  target.action = visualization_msgs::Marker::ADD;

  return 0;
}

bool Location::isNearTarget(const visualization_msgs::Marker &target) {
  float actual_dis_x, actual_dis_y;
  /// threshold represents the mininmum distance to which marker should
  /// change shape from cube to sphere
  float threshold = 1;
  actual_dis_x = fabs(target.pose.position.x - odom_x);
  actual_dis_y = fabs(target.pose.position.y - odom_y);

  return (actual_dis_x < threshold) && (actual_dis_y < threshold);
}

int Location::visualizeLocations(int argc, char** argv) {
  /// setting loop frequency to 30
  ros::Rate r(30);
  bool objectHasBeenPicked = false;
  /// Converting char** to integer
  int startLocation = atoi(argv[1]);
  int endLocation = atoi(argv[2]);
  if (argc == 1)
    return 0;
  while (ros::ok()) {
    if (!objectHasBeenPicked) {
      if (isNearTarget(stationMarkers[startLocation])) {
        displayTargetLocation(stationMarkers[startLocation]);
        objectHasBeenPicked = true;
      }
    } else {
      if (isNearTarget (stationMarkers[endLocation]))
        displayTargetLocation(stationMarkers[endLocation]);
    }
    ROS_INFO_STREAM("I am here");
    publishStationLocations();
    ros::spinOnce();
    r.sleep();
  }
  return 0;
}

Location::~Location() {
}

