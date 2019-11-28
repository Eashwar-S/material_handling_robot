#include "Pickupdropoff.hpp"

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv) {
  // Initialize the simple_navigation_goals node
  // I am changing the node name to pick_objects
  ros::init(argc, argv, "pickupdropoff");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);
  // Wait 5 sec for move_base action server to come up
  while (!ac.waitForServer(ros::Duration(5.0))) {
    ROS_INFO("Waiting for the move_base action server to come up");
  }
  std::unique_ptr < Pickupdropoff > move;
  move_base_msgs::MoveBaseGoal goal;
  bool pick = move->pickUpLocation(-2.0, 1.0, 1.0);
  bool drop = move->dropOffLocation(0.0, 0.0, -1.0);
  bool pick1 = move->goToPickUpLocation(goal);
  ROS_INFO("Sending goal");
  ac.sendGoal(goal);

  // Wait an infinite time for the results
  ac.waitForResult();
  if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
    ROS_INFO("1st Goal is successfully reached");

    //setting up a dealy for 5 sec for the robot to reeive the next goal
    ros::Duration(5.0).sleep();
    bool drop1 = move->goToDropOffLocation(goal);
    ROS_INFO("Sending goal");
    ac.sendGoal(goal);

    // Wait an infinite time for the results
    ac.waitForResult();

    // Check if the robot reached its 2nd goal
    if (ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED) {
      ROS_INFO("2nd Goal is successfully reached");
      ros::Duration(5.0).sleep();
    } else
      ROS_INFO("The robot could not reach the second goal for some reason");
  }
  else
      ROS_INFO("The robot could not reach the first goal for some reason");
  return 0;
}
