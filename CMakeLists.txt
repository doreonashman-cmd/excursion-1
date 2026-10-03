cmake_minimum_required(VERSION 3.8)
project(my_package)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 1. Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# 2. Publisher Target
add_executable(my_publisher_node src/my_publisher_node.cpp)
target_compile_features(my_publisher_node PUBLIC c_std_99 cxx_std_17)
ament_target_dependencies(my_publisher_node rclcpp std_msgs)

# 3. Subscriber Target
add_executable(listener src/my_subscriber_node.cpp)
target_compile_features(listener PUBLIC c_std_99 cxx_std_17)
ament_target_dependencies(listener rclcpp std_msgs)

# 4. Install executables so 'ros2 run' can find them
install(TARGETS
  my_publisher_node
  listener
  DESTINATION lib/${PROJECT_NAME})

# 5. Testing (Optional)
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()