#include "psub2-1/pub.hpp"
Pub::Pub() : Node("mypub"), count_(0)
{
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
    pub_ = this->create_publisher<std_msgs::msg::Int32>("mytopic", qos_profile);
    timer_ = this->create_wall_timer(50ms, std::bind(&Pub::publish_msg, this));
}
void Pub::publish_msg()
{
    auto msg = std_msgs::msg::Int32();
    static int m = 0;
    msg.data = m++;
    RCLCPP_INFO(this->get_logger(), "Published message: '%d'", msg.data);
    pub_->publish(msg);
    }