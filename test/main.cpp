#include <gtest/gtest.h>
#include <ros/ros.h>
#include "location.hpp"
#include <memory>

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "vmarkersTest");
  return RUN_ALL_TESTS();
}
