#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <memory>
#include <chrono>
#include <functional>
//#include <string>
using namespace std::chrono_literals;
void callback(rclcpp::Node::SharedPtr node,
rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub)
{
    auto message = geometry_msgs::msg::Twist();
    char c;
    std::cout<<"키 입력>>";
    std::cin>>c;
    if(c == 'f')
        message.linear.x = 1;
    else if(c == 'b')
        message.linear.x = -1;
    else if(c == 'l')
        message.angular.z = -1;    
    else if(c == 'r')
        message.angular.z = 1;
    RCLCPP_INFO(node->get_logger(), "Publish: linear x %lf anguler z %lf ", message.linear.x, message.angular.z);
    pub->publish(message);
}
int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("mynode");
    auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10));
    auto pub = node->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", qos_profile
    );
    std::function<void()> fn = std::bind(callback, node, pub);
    auto timer = node->create_wall_timer(100ms, fn);
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}