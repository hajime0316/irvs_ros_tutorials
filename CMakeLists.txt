cmake_minimum_required(VERSION 2.8.3)
project(irvs_ros_tutorials)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
)

# Generate messages in the 'msg' folder
add_message_files(
  FILES
  msgTutorial.msg
)

# サービスファイルの設定
add_service_files(
  FILES
  srvTutorial.srv
)

# Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES irvs_ros_tutorials
  CATKIN_DEPENDS roscpp std_msgs
)

###########
## Build ##
###########

# Specify additional locations of header files
# Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

# ros_tutorial_msg_publisherノードの設定
# 実行ファイル、ターゲットリンクライブラリ、追加の依存関係などを設定
add_executable(ros_tutorial_msg_publisher
src/ros_tutorial_msg_publisher.cpp)
add_dependencies(ros_tutorial_msg_publisher ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ros_tutorial_msg_publisher ${catkin_LIBRARIES})

# ros_tutorial_msg_subscriberノードの設定
# 実行ファイル、ターゲットリンクライブラリ、追加の依存関係などを設定
add_executable(ros_tutorial_msg_subscriber
src/ros_tutorial_msg_subscriber.cpp)
add_dependencies(ros_tutorial_msg_subscriber ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ros_tutorial_msg_subscriber ${catkin_LIBRARIES})

# ros_tutorial_srv_serverサービスサーバノードの設定
# 実行ファイル、ターゲットリンクライブラリ、追加の依存関係などを設定
add_executable(ros_tutorial_srv_server src/ros_tutorial_srv_server.cpp)
add_dependencies(ros_tutorial_srv_server ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ros_tutorial_srv_server ${catkin_LIBRARIES})
# ros_tutorial_srv_clientサービスクライアントノードの設定
# 実行ファイル、ターゲットリンクライブラリ、追加の依存関係などを設定
add_executable(ros_tutorial_srv_client src/ros_tutorial_srv_client.cpp)
add_dependencies(ros_tutorial_srv_client ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ros_tutorial_srv_client ${catkin_LIBRARIES})
