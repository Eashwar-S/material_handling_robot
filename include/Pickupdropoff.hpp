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
 * @file Pickupdropoff.hpp
 *
 * @author Akwasi A Obeng(Navigator)  Eashwar Sathyamurthy(Driver)
 *
 * @brief declaration for Location class
 *
 * @version 1
 *
 * @date 2019-12-06
 *
 * This .hpp file has declarations for the class attributes and methods for
 * simple functionality of picking up the materials and sropping off in the 
 * desired location by the turtlebtot.
 *
 */
#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <memory>
#include "Stations.hpp"

#ifndef SRC_MATERIAL_HANDLING_ROBOT_INCLUDE_PICKUPDROPOFF_HPP_
#define SRC_MATERIAL_HANDLING_ROBOT_INCLUDE_PICKUPDROPOFF_HPP_

typedef actionlib::SimpleActionClient
<move_base_msgs::MoveBaseAction> MoveBaseClient;
/**
 *
 * @brief declaration of Pickupdropoff class
 *
 */
class Pickupdropoff {
 private:
  Stations s;

 public:
  /**
   * @brief method called to update the target location
   *
   * @param goal a message of MoveBase Goal containing the position
   * and orientation paramenters of the target
   * 
   * @param target integer ranging from 0 to 4 use to select the target
   * location out of 5 avialable ones.
   *
   * @return bool true or false to indicate success
   *
   */
  bool updateLocation(move_base_msgs::MoveBaseGoal &goal, int target);
  /**
   * @brief method used to move the turtlebot to desired location.
   *
   * @param ac  an object of MoveBaseClient use to send goal to the turtlebot.
   * 
   * @param goal a message of MoveBase Goal containing the position
   * and orientation paramenters of the target
   * 
   * @param test a boolean used for testing purpose
   *
   * @return bool true or false to indicate success
   *
   */
  bool goToLocation(MoveBaseClient &ac,
                    const move_base_msgs::MoveBaseGoal &goal, bool test);
  /**
   * @brief Method used to move the turtlebot from first station to 
   * target station.
   *
   * @param ac  an object of MoveBaseClient use to send goal to the turtlebot.
   * 
   * @param goal a message of MoveBase Goal containing the position
   * and orientation paramenters of the target
   * 
   * @param startLocation an integer ranging between 0 and 4 used to select the 
   * starting station from which material has to be picked.
   * 
   *  @param endLocation an integer ranging between 0 and 4 used to select the 
   * ending station to which material has to be dropped off.
   * 
   * @param test a boolean used for testing purpose
   *
   * @return bool true or false to indicate success
   *
   */
  bool goToPickAndDrop(move_base_msgs::MoveBaseGoal &goal, MoveBaseClient &ac,
                       int startLocation, int endLocation, bool test);
  /**
   *
   * @brief destructor to destroy the Pickupdropoff class object
   *
   * @param none
   *
   * @return none
   *
   */
  ~Pickupdropoff();
  /**
   *
   * @brief default constructor
   *
   * @param none
   *
   * @return none
   *
   */
  Pickupdropoff();
};

#endif  // SRC_MATERIAL_HANDLING_ROBOT_INCLUDE_PICKUPDROPOFF_HPP_

