#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <memory>
#include "Stations.hpp"


typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

class Pickupdropoff {
 private:
   Stations s;
   int startLocation;
   int endLocation;

 public:
  bool goToPickUpLocation(move_base_msgs::MoveBaseGoal &goal);
  bool goToDropOffLocation(move_base_msgs::MoveBaseGoal &goal);
  ~Pickupdropoff();
   Pickupdropoff(int startL,int endL);
};
