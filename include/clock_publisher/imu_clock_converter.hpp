// Copyright 2020 Tier IV, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef CLOCK_PUBLISHER_CLOCK_PUBLISHER_H
#define CLOCK_PUBLISHER_CLOCK_PUBLISHER_H 

#include <string>

#include <rclcpp/rclcpp.hpp>

#include <rosgraph_msgs/msg/clock.hpp>
#include <sensor_msgs/msg/imu.hpp>

// Create enum with ok and warn types

class ImuClockConverter : public rclcpp::Node
{
public:
  ImuClockConverter(const rclcpp::NodeOptions & node_options);

private:
  // Timer
  void onImuMsg(const sensor_msgs::msg::Imu::SharedPtr msg);
  rclcpp::Publisher<rosgraph_msgs::msg::Clock>::SharedPtr clock_pub_;
  rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_sub_;
};

#endif
