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
 * @file vmarkersTest.cpp
 *
 * @author Part1: Eashwar Sathyamurthy(Driver)  Akwasi A Obeng(Navigator)
 *
 * @brief test cases (Google Test framework) for vmarker node
 *
 * @version 1
 *
 * @date 2019-12-06
 *
 * This .cpp file has test cases definitions for the class methods
 * of Postion, Stations and Location classes
 *
 */

#include <gtest/gtest.h>
#include <ros/ros.h>
#include <iostream>
#include <memory>
#include "Location.hpp"
/**
 *@brief Unit Test for testing displayStations method in Location class
 *
 *This test checks if the return value of the method is 0 for 
 *successful display of stations
 *
 */
TEST(vmarkersTest, testingdisplayStationsMethod) {
  Location locate;
  EXPECT_EQ(0 , locate.displayStations());
}
/**
 *@brief Unit Test for testing getStations method in Stations class
 *
 *This test checks if the method returns same position by creating a 
 * a object of Position class.
 *
 */
TEST(vmarkersTest, testinggetStationsMethod) {
  Stations station;
  Position p1(-2, 3);
  std::vector<Position> stations;
  std::vector<Position> result = station.getStations();
  stations.push_back(p1);
  /// Checking x-coordinate of the position
  EXPECT_EQ(stations[0].getX() , result[0].getX());
  /// Checking y-coordinate of the position
  EXPECT_EQ(stations[0].getY() , result[0].getY());
}
/**
 *@brief Unit Test for testing getX method in Position class
 *
 *This test checks if the method returns same x-coordinate by creating a 
 * a object of Position class.
 *
 */
TEST(vmarkersTest, testinggetXMethod) {
  Position pos(-2, 3);
  EXPECT_EQ(-2 , pos.getX());
}
/**
 *@brief Unit Test for testing getY method in Position class
 *
 *This test checks if the method returns same y-coordinate by creating a 
 * a object of Position class.
 *
 */
TEST(vmarkersTest, testinggetYMethod) {
  Position pos(-2, 3);
  EXPECT_EQ(3, pos.getY());
}
/**
 *@brief Unit Test for testing setMarkerProperties method in Location class
 *
 *This test checks if the return value of the method is 0 for 
 *successful setting the properties of stations
 *
 */
TEST(vmarkersTest, testingsetMarkerPropertiesMethod) {
  Location locate;
  Stations station;
  Position p1(-2, 3);
  std::vector<Position> stations;
  stations.push_back(p1);
  visualization_msgs::Marker m;
  Position pos(1, 2);
  EXPECT_EQ(0, locate.setMarkerProperties(2, 1, stations[0], m));
}
/**
 *@brief Unit Test for testing publishStationLocations method in LOcation class
 *
 *This test checks if the return value of the method is 0 for 
 *successfully publishing station locations.
 *
 */
TEST(vmarkersTest, testingpublishStationLocationsMethod) {
  Location locate;
  EXPECT_EQ(0, locate.publishStationLocations());
}
/**
 *@brief Unit Test for testing displayTargetLocation method in Location class
 *
 *This test checks if the return value of the method is 0 for 
 *successfully displaying target locations.
 *
 */
TEST(vmarkersTest, testingdisplayTargetLocationMethod) {
  std::unique_ptr<Location> locate;
  visualization_msgs::Marker m;
  EXPECT_EQ(0, locate->displayTargetLocation(m));
}
/**
 *@brief Unit Test for testing isNearTarget method in Location class
 *
 *This test checks if the return value of the method is true or false to 
 *Know if the robot is near the target or not.
 *
 */
TEST(vmarkersTest, testingisNearTargetMethod) {
  Location locate;
  visualization_msgs::Marker m;
  EXPECT_EQ(true, locate.isNearTarget(m));
}
/**
 *@brief Unit Test for testing visualizeLocations method in Location class
 *
 *This test checks if the return value of the method is 0 for 
 *successfully visualizing locations.
 *
 */
TEST(vmarkersTest, testingvisualizeLocationsMethod) {
  Location locate;
  char *str[] = {(char*)"2"};
  EXPECT_EQ(0, locate.visualizeLocations(1, str));
}
