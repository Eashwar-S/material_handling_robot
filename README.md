[![Build Status](https://travis-ci.org/mesneym/material_handling_robot.svg?branch=master)](https://travis-ci.org/mesneym/material_handling_robot)
[![Coverage Status](https://coveralls.io/repos/github/mesneym/material_handling_robot/badge.svg?branch=master)](https://coveralls.io/github/mesneym/material_handling_robot?branch=master)
# Material_Handling_Robot

## Overview
In recent times, significant developments have been made in robots that transport goods from one location to another. Most of them have functionality of moving between locations in some structed environment. However, it is of essence that these robots be able to navigate their  environment effectively and efficiently whilst avoiding obstacles.  

Developed in this project is a robot with the capability of moving from one station(pickup) to another(dropoff) by following some optimal path whilst avoiding obstacles.


## Project Description
Two randomized stations are selected from a fixed number of colored stations to be used as the pickup and dropoff stations. The desired stations to be used are specified by the user. The turtlebot(robot) then moves from the pickup location to the dropoff location by using Simultaneous Localization and Mapping (SLAM) to localize itself in the environment
and Djikstra algorithm to find the some desired optimal path.    

#### Components
Project is segmented into 3 key components. 
1. Station Component - This component is used to represent the different colored stations used in the project

2. Visualization Component - This component is used to visualize the output. Rviz is used to check the functionality of monte carlo localization and Djikstra algorithm and Gazebo is used to track the robot’s path.

3. Optimal path Component - This component helps the robot to find optimal path to  reach the target location by using Djikstra algorithm. This has been already been implemented
one of the packages utilized in the project

For full overview of project refer to the UML diagrams in UML folder.

#### Algorithms used:
1. Monte Carlo Localization Algorithm - Monte carlo localization is used to make the robot localize itself in the environment using a particle filter. Firstly, this algorithm assumes it is equally likely for the robot to be in any point in the environment. This means that the particles are located randomly throughout the environment. When the robot moves, it shifts the particle to determine the new state of the robot. Whenever, the robot detects an obstacles, it resamples the particles and make the particles converge to the current position of the robot. This has already been implemented and its functionality is utilized by importing a some specified package.  

#### Assumptions
1. The environment is static not dynamic
2. Markers are used as dropoff and pickup stations

#### Dependencies
To run the program below, the following need to be installed
1. ROS kinetic
2. Cmake 2.8.13
3. Gazebo
4. Rviz
5. Turtlebot package for ROS kinetic

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

### Powerpoint Slide
Click on [link](https://docs.google.com/presentation/d/11KiUA9ghvn5jOhlqSudXs_JKCjTtH-adGAJvypEEJmM/edit?usp=sharing) to view Powerpoint Slides


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

Stations colors and their respective numbers are listed as follows:  
Red -> 0,
Green -> 1,
Yellow -> 2,
Blue -> 3,
Pink -> 4

Follow the steps specified below to launch project
```
cd catkin_ws
source devel/setup.bash
roslaunch material_handling_robot material_handling_robot.launch pickupLocation:=<number> dropoffLocation:=<number>
```

For example to move from Yellow station to Blue station run the following command

```
roslaunch material_handling_robot material_handling_robot.launch pickupLocation:=2 dropoffLocation:=3

```

The default with no arguments will move turtlebot from red station to green station
```
roslaunch material_handling_robot material_handling_robot.launch
```

#### Visualizing Locations
After launching project, follow the steps below to visualize station locations  
1.Click on Rviz  
2.Click on Add   
3.Select Markers  


## Personal Information:

We (Eashwar Sathyamurthy and Akwasi A Obeng) both are pursuing Masters in Engineering specializing in Robotics in University of Maryland. We both are first year graduate students. We mainly chose to do this project as it resonated with our interests.



