cmake_minimum_required(VERSION 3.16)
project(dd)
if(NOT CMAKE_CXX_STANDARD)
set(CMAKE_CXX_STANDARD 14)
endif()
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()
# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
#build
add_executable(dd src/dd.cpp)
ament_target_dependencies(dd rclcpp std_msgs)
# Install
install(TARGETS
  dd
  DESTINATION lib/${PROJECT_NAME})
ament_package()