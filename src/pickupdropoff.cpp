#include "Pickupdropoff.hpp"


Pickupdropoff::~Pickupdropoff() {}
Pickupdropoff::Pickupdropoff() {}

bool Pickupdropoff::goToPickUpLocation(move_base_msgs::MoveBaseGoal &goal) {
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();

   //define a position and orientation for the robot to reach
    
  goal.target_pose.pose.position.x = (s.getStations())[1].getX();
  goal.target_pose.pose.position.y = (s.getStations())[1].getY();
  goal.target_pose.pose.orientation.w = 1.00;
  return true;
}

bool Pickupdropoff::goToDropOffLocation(move_base_msgs::MoveBaseGoal &goal) {
  goal.target_pose.header.frame_id = "map";
  goal.target_pose.header.stamp = ros::Time::now();
  goal.target_pose.pose.position.x = (s.getStations())[2].getX();
  goal.target_pose.pose.position.y = (s.getStations())[2].getY();
  goal.target_pose.pose.orientation.w = -1;
  return true;

}


