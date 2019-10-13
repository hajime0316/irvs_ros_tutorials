#include "irvs_ros_tutorials/srvTutorial.h"
#include <ros/ros.h>

bool calculation(irvs_ros_tutorials::srvTutorial::Request& req,
                 irvs_ros_tutorials::srvTutorial::Response& res)
{
    res.result = req.a + req.b;
    ROS_INFO("request: x = %ld, y = %ld", (long int)req.a, (long int)req.b);
    ROS_INFO("sending back response: [%ld]", (long int)res.result);

    return true;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "ros_tutorial_srv_server");
    ros::NodeHandle nh;

    // サービスサーバ宣言
    ros::ServiceServer ros_tutorial_service_server =
        nh.advertiseService("ros_tutorial_srv", calculation);

    // サービスサーバが実行したことを表示する
    ROS_INFO("ready srv server!");

    // サービスリクエストを待機する
    ros::spin();

    return 0;
}
