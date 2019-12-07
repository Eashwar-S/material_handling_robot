#include "Pickupdropoff.hpp"


Pickupdropoff::~Pickupdropoff() {}
Pickupdropoff::Pickupdropoff(int startL,int endL) {
  startLocation = startL;
  endLocation = endL;
}

bool Pickupdropoff::goToPickUpLocation(move_base_msgs::MoveBaseGoal &goal) {
  // goal.target_pose.header.frame_id = "map";
  // goal.target_pose.header.stamp = ros::Time::now();

   //define a position and orientation for the robot to reach
  goal.target_pose.pose.position.x = (s.getStations())[startLocation].getX();
  goal.target_pose.pose.position.y = (s.getStations())[startLocation].getY();
  goal.target_pose.pose.orientation.w = 1.00;
  return true;
}

bool Pickupdropoff::goToDropOffLocation(move_base_msgs::MoveBaseGoal &goal) {
  // goal.target_pose.header.frame_id = "map";
  // goal.target_pose.header.stamp = ros::Time::now();
  goal.target_pose.pose.position.x = (s.getStations())[endLocation].getX();
  goal.target_pose.pose.position.y = (s.getStations())[endLocation].getY();
  goal.target_pose.pose.orientation.w = -1;
  return true;
}


