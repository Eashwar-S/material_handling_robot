#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <memory>
#include "Stations.hpp"


#ifndef INCLUDE_PICKUPDROPOFF_HPP_
#define INCLUDE_PICKUPDROPOFF_HPP_

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;


class Pickupdropoff {
 private:
   Stations s;
   //MoveBaseClient ac("move_base", true);

 public:
  bool updateLocation(move_base_msgs::MoveBaseGoal &goal,int target);
  bool goToLocation(MoveBaseClient &ac,const move_base_msgs::MoveBaseGoal &goal);
  bool goToPickDrop();
  bool goToPickAndDrop(move_base_msgs::MoveBaseGoal &goal,MoveBaseClient &ac, int startLocation, int endLocation);

  ~Pickupdropoff();
   Pickupdropoff();
};

#endif  //INCLUDE_PICKUPDROPOFF_HPP_
