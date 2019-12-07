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

### Google Spreadsheet AIP
Click on [link](https://drive.google.com/file/d/1qtUF3zVZq3WPwMe-tqsNadlGDdAg_yqe/view?usp=sharing) to view Spreadsheet

### Sprint Planning Notes
Click on [link](https://docs.google.com/document/d/1Gug4z3o0OprYMuxE-jDm3AfoFI3M0aBzy0Ka1AaFv9c/edit?usp=sharing) to view Sprint Planning Google Doc file


