cmake_minimum_required(VERSION 3.16)
project(pub2-3)
if(NOT CMAKE_CXX_STANDARD)
set(CMAKE_CXX_STANDARD 1
endif()
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()
# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
#build
add_executable(pub2-3 src/pub2-3.cpp)
ament_target_dependencies(pub2-3 rclcpp std_msgs geometry_msgs)

# Install
install(TARGETS
  pub2-3
  DESTINATION lib/${PROJECT_NAME})
ament_package()