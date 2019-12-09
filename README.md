[![Build Status](https://travis-ci.org/mesneym/material_handling_robot.svg?branch=test)](https://travis-ci.org/mesneym/material_handling_robot)
[![Coverage Status](https://coveralls.io/repos/github/mesneym/material_handling_robot/badge.svg?branch=test)](https://coveralls.io/github/mesneym/material_handling_robot?branch=test)
# Material_Handling_Robot

## Overview
In this project, we build a robot with capability that allows it to navigate its environment effectively and efficiently despite obstacles. We have integrated ROS into gazebo and rviz to test the functionality of the robot.
 

## Project Description
The robot takes the pickup and dropoff location coordinates as input from the user. Then the robot uses Simultaneous Localization and Mapping (SLAM) to localize itself in the environment. Then with the help of A* algorithm the robot finds the optimal path between the pickup and dropoff location. Finally, the robot starts moving and transport the goods to the desired location. For brevity, we are using turtlebot robot which is an open source robot personal kit in ROS. 

#### Components
Project is segmented into 3 key components. 
1. SLAM Component: This component helps the robot to localize itself using Monte Carlo localization algorithm.

2. Optimal path Component - This component helps the robot to find optimal path to  reach the target location by using A* algorithm.

3. Visualization Component - This component is used to visualize the output. Rviz is the visualization component and Gazebo can be both used for visualization and simulation component. Rviz is used to check the functionality of monte carlo localization and A* algorithm and Gazebo is used to track the robot’s path.
For full overview of project refer to the UML diagrams in UML folder.
#### Algorithms used:
1. Monte Carlo Localization Algorithm - Monte carlo localization is used to make the robot localize itself in the environment using a particle filter. Firstly, this algorithm assumes it is equally likely for the robot to be in any point in the environment. This means that the particles are located randomly throughout the environment. When the robot moves, it shifts the particle to determine the new state of the robot. Whenever, the robot detects an obstacles, it resamples the particles and make the particles converge to the current position of the robot. 

2. A* algorithm – A* algorithm is mainly employed to find the optimal path. It considers many nodes between the starting and target location and estimates the cost taken to move from one node to another. It obtains optimal path by choosing the node which produces minimum cost when substituted in the cost function. The cost function is given by:   
  f(n) = g(n) + h(n)  
where f(n) is the cost function  
      n is the next node  
      g(n) is the cummulative cost of the path from node 0 to n  
      h(n) is the heuristic function that estimates the cost of the cheapest path from node n to goal node.  


#### Assumptions
1. The environment is static not dynamic
2. Creating markers and assuming them as goods as turtlebot cannot lift the material.
3. The user must have Ubuntu 16.04 LTS version installed.
4. The user must have ROS kinetic and catkin installed.

## Executables Added:
In CMakeLists.txt the following executables are added to execute cpp files in src folder:
```
add_executable(pickupdropoff src/main.cpp src/pickupdropoff.cpp src/Position.cpp src/Stations.cpp)
add_executable(vmarker src/main2.cpp src/location.cpp src/Position.cpp src/Stations.cpp)
```

## Target Link Libraries Added:
In CMakeLists.txt the following target link libraries to link executables:
```
target_link_libraries(pickupdropoff ${catkin_LIBRARIES})
target_link_libraries(vmarker ${catkin_LIBRARIES})
```
## To integrate google test the following libraries and dependencies were added to CMakeLists.txt:
```
if(CATKIN_ENABLE_TESTING)
  find_package(rostest REQUIRED)
  add_rostest_gtest(vmarkersTest test/vmarkers.test test/vmarkersTest.cpp test/main.cpp src/location.cpp src/Position.cpp src/Stations.cpp)
  target_link_libraries(vmarkersTest ${catkin_LIBRARIES})
  include_directories(include ${catkin_INCLUDE_DIRS})
endif()

if(CATKIN_ENABLE_TESTING)
  find_package(rostest REQUIRED)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 --coverage")
  add_rostest_gtest(pickupdropoffTest test/pickupdropoff.test test/pickupdropoffTest.cpp src/Stations.cpp src/Position.cpp src/pickupdropoff.cpp)
  target_link_libraries(pickupdropoffTest ${catkin_LIBRARIES})
  include_directories(include ${catkin_INCLUDE_DIRS})
endif()
```
## Added C++11 Compile option:
This is done to take advantage of C++11 features
```
add_compile_options(-std=c++11)
```
### Google Spreadsheet AIP
Click on [link](https://drive.google.com/file/d/1qtUF3zVZq3WPwMe-tqsNadlGDdAg_yqe/view?usp=sharing) to view Spreadsheet

### Sprint Planning Notes
Click on [link](https://docs.google.com/document/d/1Gug4z3o0OprYMuxE-jDm3AfoFI3M0aBzy0Ka1AaFv9c/edit?usp=sharing) to view Sprint Planning Google Doc file

## How to build
```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/
cd src/
git clone https://github.com/mesneym/material_handling_robot.git
cd ..
catkin_make
source devel/setup.bash
```
## How to build tests
```
cd catkin_ws
source devel/setup.bash
catkin_make run_tests
```
## To run tests using launch files
```
cd catkin_ws
source devel/setup.bash
rostest material_handling_robot pickupdropoff.test 

cd catkin_ws
source devel/setup.bash
rostest material_handling_robot vmarkers.test 
```
## How to run program using launch files
To run the program, the user has to specify the pickup and dropoff station. There are a fixed number of colored stations and 
the user gets to randomized the pickup and dropoff location.  

Stations colors and their respective numbers.
Red -> 0
Green -> 1
Yellow -> 2
Blue -> 3
Pink -> 4

```
cd catkin_ws
source devel/setup.bash
roslaunch material_handling_robot material_handling_robot.launch pickupLocation:=<number> dropoffLocation:=<number>

```
For example to move from Yellow station to blue station run the following command

```
roslaunch material_handling_robot material_handling_robot.launch pickupLocation:=2 dropoffLocation:=3

```

The default with no arguments will move turtlebot from red station to green station
```
roslaunch material_handling_robot material_handling_robot.launch
```

## Personal Information:

We (Eashwar Sathyamurthy and Akwasi A Obeng) both are pursuing Masters in Engineering specializing in Robotics in University of Maryland. We both are first year graduate students. We mainly chose to do this project as it resonated with our interests.
