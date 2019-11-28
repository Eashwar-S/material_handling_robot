#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <memory>

typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
class Pickupdropoff {
 public:
  double xPickUp;
  double yPickUp;
  double thetaPickUp;
  double xDropOff;
  double yDropOff;
  double thetaDropOff;
  bool pickUpLocation(double x,double y,double theta);
  bool dropOffLocation(double x,double y,double theta);
  bool goToPickUpLocation(move_base_msgs::MoveBaseGoal goal);
  bool goToDropOffLocation(move_base_msgs::MoveBaseGoal goal);

};
