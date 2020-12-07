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

#include <clock_publisher/imu_clock_converter.hpp>

#include <rclcpp/create_timer.hpp>


void ImuClockConverter::onImuMsg(const sensor_msgs::msg::Imu::SharedPtr msg)
{
  rosgraph_msgs::msg::Clock clock;
  clock.clock = msg->header.stamp;
  // std::cerr << std::fixed << rclcpp::Time(clock.clock).seconds() << std::endl;
  clock_pub_->publish(clock); 
}

ImuClockConverter::ImuClockConverter(const rclcpp::NodeOptions & node_options)
: Node("clock_publisher", node_options)
{
  clock_pub_ = this->create_publisher<rosgraph_msgs::msg::Clock>("/clock", 1);

  imu_sub_ = this->create_subscription<sensor_msgs::msg::Imu>("imu", 1, std::bind(&ImuClockConverter::onImuMsg, this, std::placeholders::_1));

}

#include <rclcpp_components/register_node_macro.hpp>

RCLCPP_COMPONENTS_REGISTER_NODE(ImuClockConverter)
