#include "Pickupdropoff.hpp"


Pickupdropoff::~Pickupdropoff() {}

Pickupdropoff::Pickupdropoff() {
}


bool Pickupdropoff::updateLocation(move_base_msgs::MoveBaseGoal &goal,int target) {


   MoveBaseClient ac("move_base", true);
   goal.target_pose.header.frame_id = "map";
   goal.target_pose.header.stamp = ros::Time::now();
  goal.target_pose.pose.position.x = (s.getStations())[target].getX();
  goal.target_pose.pose.position.y = (s.getStations())[target].getY();
  goal.target_pose.pose.orientation.w = -1;

  return true;
}


bool Pickupdropoff::goToLocation(MoveBaseClient &ac,const move_base_msgs::MoveBaseGoal &goal) {
  //Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending goal");
  ac.sendGoal(goal);

   //Wait an infinite time for the results
  ac.waitForResult();
  return ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED;
}


bool Pickupdropoff::goToPickAndDrop(move_base_msgs::MoveBaseGoal &goal,MoveBaseClient &ac, int startLocation, int endLocation) {
  updateLocation(goal,startLocation);

   //Check if the robot reached its 0st goal
  if (goToLocation(ac,goal)) {
    ROS_INFO("0st Goal is successfully reached");
    ros::Duration(4.0).sleep(); // wait 5 sec to receive next goal
    updateLocation(goal,endLocation);
  
    //Check if the robot reached its 1nd goal
    if (goToLocation(ac,goal)) {
       ROS_INFO("1nd Goal is successfully reached");
       ros::Duration(4.0).sleep();
    } 
    else
       ROS_INFO("The robot could not reach the second goal");
  }
  else
    ROS_INFO("The robot could not reach the first goal");
}

