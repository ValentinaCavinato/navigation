#ifndef BACK_OUT_RECOVERY_BEHAVIOUR
#define BACK_OUT_RECOVERY_BEHAVIOUR

#include <gazebo_msgs/SetModelState.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Twist.h>
#include <nav_core/recovery_behavior.h>

namespace back_out {
class BackOut : public nav_core::RecoveryBehavior {
private:
  ros::ServiceClient client_gazebo_;

public:
  BackOut();
  ~BackOut();

  void initialize(std::string name, tf2_ros::Buffer *tf,
                  costmap_2d::Costmap2DROS *global_costmap,
                  costmap_2d::Costmap2DROS *local_costmap){};

  void runBehavior(){};
  void runBehavior(const gazebo_msgs::ModelState &ms) {
    try{
    std::cout << "sending..." << ms.pose << std::endl;
    gazebo_msgs::SetModelState setmodelstate;
    setmodelstate.request.model_state = ms;
    client_gazebo_.call(setmodelstate);
    }
    catch(std::exception&){
      return;
    }
  };
}; // namespace back_out

} // namespace back_out

#endif