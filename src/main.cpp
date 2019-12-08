#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include "Pickupdropoff.hpp"

 //Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;


int main(int argc, char** argv) {

  ros::init(argc, argv, "pickupdropoff");//initialize node
  MoveBaseClient ac("move_base", true); //spin action thread by default

  // Wait 5 sec for move_base action server to come up
  while (!ac.waitForServer(ros::Duration(5.0))) {
    ROS_INFO("Waiting for the move_base action server to come up");
  }
  
  Pickupdropoff pickdrop;
  move_base_msgs::MoveBaseGoal goal;
  pickdrop.goToPickAndDrop(goal,ac,atoi(argv[1]),atoi(argv[2]));
}


