/******************************************************************************
 * MIT License
 *
 * Copyright (c) 2019 Akwasi A Obeng and Eashwar Sathyamurthy
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 ******************************************************************************/

/**
 * @file pickupdropoffTest.cpp
 *
 * @author Part1: Eashwar Sathyamurthy(Driver)  Akwasi A Obeng(Navigator)
 *
 * @brief test cases (Google Test framework) for pickupdropoff node
 *
 * @version 1
 *
 * @date 2019-12-06
 *
 * This .cpp file has test cases definitions for the class methods
 * of Pickupdropoff class
 *
 */

#include <gtest/gtest.h>
#include <ros/ros.h>
#include <iostream>
#include <memory>
#include "Pickupdropoff.hpp"
/**
 *@brief Unit Test for testing updateLocation Method in Pickupdropoff class
 *
 *This test checks if the return value of the method is true or false for 
 *successful update of station location
 *
 */
TEST(pickupdropoffTest, testingupdateLocationMethod) {
  Pickupdropoff pick;
  move_base_msgs::MoveBaseGoal goal;
  /// Updating the goal with first marker as target location
  EXPECT_EQ(true , pick.updateLocation(goal, 1));
}
/**
 *@brief Unit Test for testing goToLocation Method in Pickupdropoff class
 *
 *This test checks if the return value of the method is true or false to
 *check if the turtlebot has reached the desired location or not.
 *
 */
TEST(pickupdropoffTest, testinggoToLocationMethod) {
  Pickupdropoff pick;
  MoveBaseClient ac("move_base", true);
  move_base_msgs::MoveBaseGoal goal;
  EXPECT_EQ(false , pick.goToLocation(ac, goal, false));
}
/**
 *@brief Unit Test for testing goToPickAndDrop in Pickupdropoff class
 *
 *This test checks if the return value of the method is true or false to
 *check if the turtlebot has reached the second goal from first goal.
 *
 */
TEST(pickupdropoffTest, testinggoToPickAndDropMethod) {
  Pickupdropoff pick;
  /// Continuously checking move_base topic
  MoveBaseClient ac("move_base", true);
  move_base_msgs::MoveBaseGoal goal;
  /// Setting the first goal as 0 and target goal as 3
  EXPECT_EQ(false , pick.goToPickAndDrop(goal, ac, 0, 3, false));
}
/**
 *@brief main method to run all tests in pickupdropoff node
 */
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  ros::init(argc, argv, "pickupdropoffTest");
  return RUN_ALL_TESTS();
}
