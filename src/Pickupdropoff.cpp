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
 * @file Position.cpp
 *
 * @author Akwasi A Obeng(Navigator)  Eashwar Sathyamurthy(Driver)
 *
 * @brief cpp program for definition and implementation of the methods of
 *        Pickupdropoff class
 *
 * @version 1
 *
 * @date 2019-12-06
 *
 * This program implements the methods of the
 * Pickupdropoff class from Pickupdropoff.hpp header file
 *
 */
#include "Pickupdropoff.hpp"

Pickupdropoff::~Pickupdropoff() {
}

Pickupdropoff::Pickupdropoff() {
}

bool Pickupdropoff::updateLocation(move_base_msgs::MoveBaseGoal &goal,
                                   int target) {
  /// Setting the move_base to true will eliminate the need for using
  /// ros::spin() and continuously sends messages to move_base topic
  MoveBaseClient ac("move_base", true);
  /// Setting the goal id, position and orientation
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();
  goal.target_pose.pose.position.x = (s.getStations())[target].getX();
  goal.target_pose.pose.position.y = (s.getStations())[target].getY();
  goal.target_pose.pose.orientation.w = -1;

  return true;
}

bool Pickupdropoff::goToLocation(MoveBaseClient &ac,
      const move_base_msgs::MoveBaseGoal &goal, bool test) {
  ROS_INFO_STREAM("Sending goal");
  /// Sending the goal to move_base
  ac.sendGoal(goal);
  /// Waiting for infinite to get results
  if (test)
    ac.waitForResult();
  /// returning the state the move_base based on results
  return ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED;
}

bool Pickupdropoff::goToPickAndDrop(move_base_msgs::MoveBaseGoal &goal,
                                    MoveBaseClient &ac, int startLocation,
                                    int endLocation, bool test) {
  updateLocation(goal, startLocation);
  /// Checking if the robot reached its 0th goal
  if (test) {
    if (goToLocation(ac, goal, true)) {
      ROS_INFO_STREAM("0th Goal is successfully reached");
      /// waiting 4 sec to receive next goal
      ros::Duration(4.0).sleep();
      updateLocation(goal, endLocation);
      /// Checking if the turtlebot reached its 1nd goal
      if (goToLocation(ac, goal, true)) {
        ROS_INFO_STREAM("1nd Goal is successfully reached");
        ros::Duration(4.0).sleep();
      } else
        ROS_INFO_STREAM("The robot could not reach the second goal");
    } else {
      ROS_INFO_STREAM("The robot could not reach the first goal");
      return false;
    }
  } else {
    if (!goToLocation(ac, goal, false))
      return false;
  }
  return true;
}

