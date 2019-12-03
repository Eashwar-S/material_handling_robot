#include "Pickupdropoff.hpp"


Pickupdropoff::~Pickupdropoff() {}
Pickupdropoff::Pickupdropoff() {}

bool Pickupdropoff::goToPickUpLocation(move_base_msgs::MoveBaseGoal &goal){
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();
   //define a position and orientation for the robot to reach
  goal.target_pose.pose.position.x = -2;
  goal.target_pose.pose.position.y = 1;
  goal.target_pose.pose.orientation.w = 1.00;
  return true;
}

bool Pickupdropoff::goToDropOffLocation(move_base_msgs::MoveBaseGoal &goal){
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();
  goal.target_pose.pose.position.x = 0;
  goal.target_pose.pose.position.y = 0;
  goal.target_pose.pose.orientation.w = -1;
  return true;

}


