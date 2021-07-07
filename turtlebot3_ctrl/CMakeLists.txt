cmake_minimum_required(VERSION 2.8.3)
project(turtlebot3_ctrl)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  std_msgs
  roscpp
)

catkin_package(
CATKIN_DEPENDS geometry_msgs std_msgs roscpp

)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(turtlebot3_ctrl src/turtlebot3_ctrl.cpp)

target_link_libraries(turtlebot3_ctrl ${catkin_LIBRARIES})

