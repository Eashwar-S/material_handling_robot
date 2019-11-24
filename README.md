# Material_Handling_Robot

## Overview
In this project, we build a robot with capability that allows it to navigate its environment effectively and efficiently despite obstacles. We have integrated ROS into gazebo and rviz to test the functionality of the robot.
 

## Description
The module developed for this robot will help robots move to desired location whilst avoiding obstacles and finding the optimal path. The robot uses Simultaneous Localization and Mapping (SLAM) to localize itself in the environment and uses A* algorithm to find the optimal path. For brevity, we are using turtlebot robot which is an open source robot personal kit in ROS. 

#### Components
Project is segmented into 3 key components. 
1. SLAM Component: This component helps the robot to localize itself using Monte Carlo localization algorithm.

2. Optimal path Component - This component helps the robot to find optimal path to  reach the target location by using A* algorithm.

3. Visualization Component - This component is used to visualize the output. Rviz is the visualization component and Gazebo can be both used for visualization and simulation component. Rviz is used to check the functionality of monte carlo localization and A* algorithm and Gazebo is used to track the robot’s path.
For full overview of project refer to the UML diagrams in UML folder.
#### Algorithms used:
1. Monte Carlo Localization Algorithm - Monte carlo localization is used to make the robot localize itself in the environment using a particle filter. Firstly, this algorithm assumes it is equally likely for the robot to be in any point in the environment. This means that the particles are located randomly throughout the environment. When the robot moves, it shifts the particle to determine the new state of the robot. Whenever, the robot detects an obstacles, it resamples the particles and make the particles converge to the current position of the robot. 

2. A* algorithm – A* algorithm is mainly employed to find the optimal path. It considers many nodes between the starting and target location and estimates the cost taken to move from one node to another. It produces optimal path by always choosing the node which results in minimal cost. Minimal cost is the minimum value of the below mentioned cost function 
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
