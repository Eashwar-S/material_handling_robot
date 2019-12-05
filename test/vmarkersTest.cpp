#include <gtest/gtest.h>
#include <ros/ros.h>
#include "location.hpp"
#include <iostream>
#include <memory>

TEST(vmarkerTest, testingdisplayStationsMethod) {
  Location locate;
  EXPECT_EQ(0 , locate.displayStations());
}

 TEST(vmarkerTest1, testinggetStationsMethod) {
   Stations station;
   Position p1(-2, 3);
   std::vector<Position> stations;
   std::vector<Position> result = station.getStations();
   stations.push_back(p1);
   std::cout << stations[0].getX() << std::endl;
   std::cout << result[0].getX() << std::endl;
   EXPECT_EQ(stations[0].getX() , result[0].getX());
 }

TEST(vmarkerTest, testinggetXMethod) {
     Position pos(-2, 3);
     EXPECT_EQ(-2 , pos.getX());
}

 TEST(vmarkerTest, testinggetYMethod) {
   Position pos(-2, 3);
   EXPECT_EQ(3,pos.getY());
 }

 TEST(vmarkerTest, testingsetMarkerPropertiesMethod) {
   Location locate;
   Stations station;
   Position p1(-2, 3);
   std::vector<Position> stations;
   stations.push_back(p1);
   visualization_msgs::Marker m;
   std::vector<Position> vec = station.getStations();
   Position pos(1,2);
   EXPECT_EQ(0,locate.setMarkerProperties(2,1,stations[0],m));
 }

 TEST(vmarkerTest, testingpublishStationLocationsMethod) {
   Location locate;
   EXPECT_EQ(0,locate.publishStationLocations());
   }

 TEST(vmarkerTest, testingdisplayTargetLocationMethod) {
   std::unique_ptr<Location> locate;
   visualization_msgs::Marker m;
   EXPECT_EQ(0,locate->displayTargetLocation(m));
 }

 TEST(vmarkerTest, testingisNearTargetMethod) {
   Location locate;
   visualization_msgs::Marker m;
   EXPECT_EQ(true,locate.isNearTarget(m));
}

 TEST(vmarkerTest, testingvisualizeLocationsMethod) {
   Location locate;
   char *str[] = {"2"};
   EXPECT_EQ(0,locate.visualizeLocations(1,str));
 }


