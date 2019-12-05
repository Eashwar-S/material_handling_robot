#include <gtest/gtest.h>
#include <ros/ros.h>
#include "Pickupdropoff.hpp"
#include <iostream>
#include <memory>

TEST(pickupdropoffTest, testinggoToPickUpLocationMethod) {
  Pickupdropoff pick(1 , 2);
  move_base_msgs::MoveBaseGoal goal;
  EXPECT_EQ(true , pick.goToPickUpLocation(goal));
}

TEST(pickupdropoffTest, testinggoToDropOffLocationMethod) {
  Pickupdropoff pick(1 , 2);
  move_base_msgs::MoveBaseGoal goal;
  EXPECT_EQ(true , pick.goToDropOffLocation(goal));
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "pickupdropoffTest");
  return RUN_ALL_TESTS();
}
