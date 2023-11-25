#include "ros/ros.h"
#include "turtlesim/Pose.h"

void poseCallback(const turtlesim::Pose::ConstPtr& msg) 
{
    ROS_INFO("Robot Pose X: %.4f, Y: %.4f, Theta: %.4f", msg->x, msg->y, msg->theta);
}

int main(int argc, char **argv) 
{
    ros::init(argc, argv, "pose_subscriber");
    ros::NodeHandle n;

    ros::Subscriber sub = n.subscribe("/turtle1/pose", 100, poseCallback);

    ros::spin();

    return 0;
}
