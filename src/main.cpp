#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include "Pickupdropoff.hpp"

 //Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv) {
  // Initialize the simple_navigation_goals node
  // I am changing the node name to pick_objects
  ros::init(argc, argv, "pick_objects");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  
  // Wait 5 sec for move_base action server to come up
  while (!ac.waitForServer(ros::Duration(5.0))) {
    ROS_INFO("Waiting for the move_base action server to come up");
  }
  int l1 = atoi(argv[1]);
  int l2 = atoi(argv[2]);
  Pickupdropoff pickdrop(l1,l2);
  move_base_msgs::MoveBaseGoal goal;
  pickdrop.goToPickUpLocation(goal);
 

    //Send the goal position and orientation for the robot to reach
  ROS_INFO("Sending goal");
  ac.sendGoal(goal);

   //Wait an infinite time for the results
  ac.waitForResult();

   //Check if the robot reached its 1st goal
  if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
  {
    ROS_INFO("1st Goal is successfully reached");

    //setting up a dealy for 5 sec for the robot to reeive the next goal
    ros::Duration(5.0).sleep();
   
    pickdrop.goToDropOffLocation(goal);
     //Send the goal position and orientation for the robot to reach
    ROS_INFO("Sending goal");
    ac.sendGoal(goal);

     //Wait an infinite time for the results
    ac.waitForResult();
  
     //Check if the robot reached its 2nd goal
    if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    {
       ROS_INFO("2nd Goal is successfully reached");
       ros::Duration(5.0).sleep();
    }
    else
       ROS_INFO("The robot could not reach the second goal for some reason");
  }
  else
    ROS_INFO("The robot could not reach the first goal for some reason");
}


