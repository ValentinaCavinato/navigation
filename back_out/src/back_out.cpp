#include "back_out.h"
#include <pluginlib/class_list_macros.h>

PLUGINLIB_EXPORT_CLASS(back_out::BackOut, nav_core::RecoveryBehavior)
namespace back_out {

BackOut::BackOut(/* args */) {
    ros::NodeHandle private_nh("~");
  client_gazebo_ = private_nh.serviceClient<gazebo_msgs::SetModelState>(
      "/gazebo/set_model_state");
}

BackOut::~BackOut() {}
} // namespace back_out