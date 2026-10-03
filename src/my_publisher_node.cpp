#include <chrono>
#include <functional>
#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
using namespace std::chrono_literals;

  class MinimalPublisher : public rclcpp::Node{

  public:
  MinimalPublisher() : Node("minimal_publisher"), count_(0){
    
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);

    timer_ = this->create_wall_timer(500ms, std::bind(&MinimalPublisher::timer_callback, this));
  }

  private:
    void timer_callback(){
      auto message = std_msgs::msg::String(); //Create a member variable of type string
      message.data = "This is the excursion test message! " + std::to_string(count_++); // Define the string data
      RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str()); //
      publisher_->publish(message);
    }
    rclcpp::TimerBase::SharedPtr timer_; //Create a timer shared pointer
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_; //Create a publisher shared pointer.
    size_t count_;
  };

  int main(int argc, char *argv[]){
  rclcpp::init(argc, argv); //Initialize ROS2 communication
  rclcpp::spin(std::make_shared<MinimalPublisher>()); //Create instance of MinimalPublisher, enter loop to constantly publish
  rclcpp::shutdown(); //Clean up and shut down ROS2 communication
  return 0;
  }



