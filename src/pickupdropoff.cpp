#include "Pickupdropoff.hpp"

bool Pickupdropoff::pickUpLocation(double x,double y,double theta){
  xPickUp = x;
  yPickUp = y;
  thetaPickUp = theta;
  return true;
}

bool Pickupdropoff::dropOffLocation(double x,double y,double theta){
  xDropOff = x;
  yDropOff = y;
  thetaDropOff = theta;
  return true;
}

bool Pickupdropoff::goToPickUpLocation(move_base_msgs::MoveBaseGoal goal){

  // set up the frame parameters
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();
  // Define a position and orientation for the robot to reach
  goal.target_pose.pose.position.x = xPickUp;
  goal.target_pose.pose.position.y = yPickUp;
  goal.target_pose.pose.orientation.w = thetaPickUp;
  return true;
}

bool Pickupdropoff::goToDropOffLocation(move_base_msgs::MoveBaseGoal goal){
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();
  goal.target_pose.pose.position.x = xDropOff;
  goal.target_pose.pose.position.y = yDropOff;
  goal.target_pose.pose.orientation.w = thetaDropOff;
  return true;

}

