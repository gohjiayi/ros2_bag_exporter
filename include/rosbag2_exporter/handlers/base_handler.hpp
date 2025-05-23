/*
 * Author: Abdalrahman M. Amer, www.linkedin.com/in/abdalrahman-m-amer
 * Date: 13.10.2024
 */

#ifndef ROSBAG2_EXPORTER__HANDLERS__BASE_HANDLER_HPP_
#define ROSBAG2_EXPORTER__HANDLERS__BASE_HANDLER_HPP_

#include <string>
#include <rclcpp/serialization.hpp>
#include <rclcpp/serialized_message.hpp>
#include <rclcpp/logger.hpp>
#include <iomanip>
#include <sstream>

namespace rosbag2_exporter
{

class BaseHandler
{
public:
  virtual ~BaseHandler() = default;

  // Pure virtual function to process messages
  virtual void process_message(const rclcpp::SerializedMessage & serialized_msg,
                               const std::string & topic,
                               size_t index) = 0;

protected:
  rclcpp::Logger logger_;

  // Constructor to initialize the logger
  BaseHandler(rclcpp::Logger logger) : logger_(logger) {}

  // Utility function to standardize timestamp formatting
  template<typename TimeType>
  static std::string format_timestamp(const TimeType& stamp) {
    std::stringstream ss;
    ss << stamp.sec << "-" << std::setw(9) << std::setfill('0') << stamp.nanosec;
    return ss.str();
  }
};

}  // namespace rosbag2_exporter

#endif  // ROSBAG2_EXPORTER__HANDLERS__BASE_HANDLER_HPP_
