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
 * @file Location.hpp
 *
 * @author Akwasi A Obeng(Driver)  Eashwar Sathyamurthy(Navigator)
 *
 * @brief declaration for Location class
 *
 * @version 1
 *
 * @date 2019-12-06
 *
 * This .hpp file has declarations for the class attributes and methods for
 * simple functionality of pathplanning of turtlebot.
 *
 */
#include <visualization_msgs/Marker.h>
#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <vector>
#include <bitset>
#include "nav_msgs/Odometry.h"
#include "Stations.hpp"

#ifndef SRC_MATERIAL_HANDLING_ROBOT_INCLUDE_LOCATION_HPP_
#define SRC_MATERIAL_HANDLING_ROBOT_INCLUDE_LOCATION_HPP_
/**
 *
 * @brief declaration of Location class
 *
 */
class Location {
 private:
  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;
  /// Publisher to publish messages to visualization_marker topic
  ros::Publisher vmarker_pub;
  /// Subscriber to subscribe messages from odom topic
  ros::Subscriber sub;
  float odom_x, odom_y;
  Stations stations;
  std::vector<visualization_msgs::Marker> stationMarkers;
  /**
   * @brief method called when subscribing to odom topic
   *
   * @param msg initialize the odometry parameters
   *
   * @return none
   *
   */
  void odomCallback(const nav_msgs::Odometry::ConstPtr &msg);

 public:
  /**
   *
   * @brief default constructor to initialize the private members
   *
   * @param none
   *
   * @return none
   *
   */
  Location();
  /**
   *
   * @brief destructor to destroy the Location class object
   *
   * @param none
   *
   * @return none
   *
   */
  ~Location();
  /**
   * @brief Used to visulize the markers in specified location
   *
   * @param argc number of arguments
   * 
   * @param argv a pointer to a pointer of char
   *
   * @return int 0 or 1 to indicate success
   *
   */
  int visualizeLocations(int argc, char **argv);
  /**
   * @brief method to display the stations(markers)
   *
   * @param none
   *
   * @return int 0 or 1 to indicate success
   *
   */
  int displayStations();
  /**
   * @brief method to publish station location
   *
   * @param none
   *
   * @return int 0 or 1 to indicate success
   *
   */
  int publishStationLocations();
  /**
   * @brief method to change  the time interval
   *
   * @param newDtValue variable for new dt value
   *
   * @return bool to indicate that the robot is near the target or not.
   *
   */
  bool isNearTarget(const visualization_msgs::Marker &target);
  /**
   * @brief method to display target location(marker) as a sphere
   *
   * @param dropoff a pointer to a marker
   *
   * @return int 0 or 1 to indicate success
   *
   */
  int displayTargetLocation(visualization_msgs::Marker &dropOff);
  /**
   * @brief method set the properties of the marker
   *
   * @param color int to give colour to the marker.
   * 
   * @param id int to give unique id to the marker
   * 
   * @param p an object to the position class
   * 
   * @param m a pointer of the marker
   *
   * @return int 0 or 1 to indicate success
   *
   */
  int setMarkerProperties(int color, int id, Position p,
                          visualization_msgs::Marker &m);
};  
#endif  // SRC_MATERIAL_HANDLING_ROBOT_INCLUDE_LOCATION_HPP_

