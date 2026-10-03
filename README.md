
# HOW TO SETUP
## Clone into your workspace src directory
cd ~/ros2_ws/src
git clone [https://github.com/doreonashman-cmd/excursion-1.git](https://github.com/doreonashman-cmd/excursion-1.git)

## Install dependencies
```
cd ~/ros2_ws
rosdep install --from-paths src --ignore-src -y
```

## Build the package
```
colcon build --packages-select my_package
```
# HOW TO RUN PUBLISHER/SUBSCRIBER
## Run the publisher in one terminal
```
source ~/ros2_ws/install/setup.bash
ros2 run my_package my_publisher_node
```

## Run the subscriber in another terminal
```
source ~/ros2_ws/install/setup.bash
ros2 run my_package my_subscriber_node
```
