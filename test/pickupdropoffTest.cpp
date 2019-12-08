#include <gtest/gtest.h>
#include <ros/ros.h>
#include "Pickupdropoff.hpp"
#include <iostream>
#include <memory>

//TEST(pickupdropoffTest, testinggoToLocationMethod) {
  //Pickupdropoff pick;
  //move_base_msgs::MoveBaseGoal goal;
  //MoveBaseClient ac("move_base", true); 

  //while (!ac.waitForServer(ros::Duration(5.0))) {
    //ROS_INFO("Waiting for the move_base action server to come up");
  //}

  //EXPECT_EQ(true , pick.goToLocation(ac, goal));
//}


TEST(pickupdropoffTest, testingupdateLocationMethod) {
  Pickupdropoff pick;
  move_base_msgs::MoveBaseGoal goal;
  EXPECT_EQ(true , pick.updateLocation(goal,1));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "pickupdropoffTest");
  return RUN_ALL_TESTS();
}
