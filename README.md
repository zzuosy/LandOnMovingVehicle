# LandOnMovingVehicle  

## 1.PX4配置  

### 1.Download PX4 Source Code  
```
git clone https://github.com/PX4/PX4-Autopilot.git --recursive
```
### 2.Run the ubuntu.sh with no arguments (in a bash shell) to install everything  
```
bash ./PX4-Autopilot/Tools/setup/ubuntu.sh
```

在配置过程中会出现各种个性化的错误，请自行百度/Google解决。
### 3.

## 2.Turtlebot3移动小车配置

### 1.安装Turtlebot3
```
cd ~/catkin_ws/src
git clone https://github.com/ROBOTIS-GIT/turtlebot3_msgs.git
git clone https://github.com/ROBOTIS-GIT/turtlebot3.git
cd ..
rosdep install --from-paths src -i -y
catkin_make
source ./devel/setup.bash
```
### 2.安装TurtleBot3 Simulation
```
cd ~/catkin_ws/src/
git clone https://github.com/ROBOTIS-GIT/turtlebot3_simulations.git
cd ..
catkin_make
source ./devel/setup.bash
```
### 3.安装键盘控制代码
```
cd ~/catkin_ws/src/
git clone https://github.com/ros-teleop/teleop_twist_keyboard.git
cd ..
catkin_make
source ./devel/setup.bash
```
### 4.加入降落平台及二维码

将aruco.dae和aruco_mip_36h12_00000.png移动到～/catkin_ws/src/turtlebot3/turtlebot3_description/meshes/sensors中  
以文本方式打开aruco.dae，将第14行的<init_from>后的USERNAME改为自己的用户名  
将turtlebot3_waffle_pi.urdf.xacro移动到~/catkin_ws/src/turtlebot3/turtlebot3_description/urdf中，替换原本的文件  
将turtlebot3_empty_world.launch移动到~/catkin_ws/src/turtlebot3_simulations/turtlebot3_gazebo/launch中，替换原来的文件  

## 3.PX4与Turtlebot3联合

将posix_sitl.launch移动到PX4_Firmware/launch中，替换原来的文件，并注意将第47行的USERNAME改为自己的用户名

### 4.仿真启动步骤
```
cd ~/Firmware
DONT_RUN=1 make px4_sitl_default gazebo
source Tools/setup_gazebo.bash $(pwd) $(pwd)/build/px4_sitl_default
export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$(pwd)
export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$(pwd)/Tools/sitl_gazebo
roslaunch px4 mavros_posix_sitl.launch
```
