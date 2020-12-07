cmake_minimum_required(VERSION 3.5)
project(clock_publisher)

### Compile options
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wno-unused-parameter -Wall -Wextra -Wpedantic)
endif()

### Dependencies
find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

### Target executable
ament_auto_add_library(clock_publisher SHARED
  src/clock_publisher.cpp
)

rclcpp_components_register_node(clock_publisher
  PLUGIN "ClockPublisher"
  EXECUTABLE clock_publisher_node
)

ament_auto_add_library(imu_clock_converter SHARED
  src/imu_clock_converter.cpp
)

rclcpp_components_register_node(imu_clock_converter
  PLUGIN "ImuClockConverter"
  EXECUTABLE imu_clock_converter_node
)

ament_auto_package(INSTALL_TO_SHARE
  launch
)

