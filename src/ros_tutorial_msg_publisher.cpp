#include "irvs_ros_tutorials/msgTutorial.h"
#include <ros/ros.h>

int main(int argc, char** argv)
{
    // ノード名の初期化
    ros::init(argc, argv, "ros_tutorial_msg_publisher");
    // ROSシステムとの通信のためのノードハンドルを宣言
    ros::NodeHandle nh;

    // 配信者ノードの宣言
    ros::Publisher ros_tutorial_pub =
        nh.advertise<irvs_ros_tutorials::msgTutorial>("ros_tutorial_msg", 100);

    // ループの周期を設定する
    ros::Rate loop_rate(10);

    // メッセージに使用する変数の宣言
    int count = 0;

    while (ros::ok) {
        irvs_ros_tutorials::msgTutorial msg;

        msg.data = count;

        ROS_INFO("send msg = %d", count);

        ros_tutorial_pub.publish(msg);

        loop_rate.sleep();

        count++;
    }

    return 0;
}
