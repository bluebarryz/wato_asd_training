#ifndef MAP_MEMORY_NODE_HPP_
#define MAP_MEMORY_NODE_HPP_

#include "rclcpp/rclcpp.hpp"

#include "map_memory_core.hpp"
#include "nav_msgs/msg/occupancy_grid.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include <cmath>

class MapMemoryNode : public rclcpp::Node {
  public:
    MapMemoryNode();

  private:
    robot::MapMemoryCore map_memory_;
    rclcpp::Subscription<nav_msgs::msg::OccupancyGrid>::SharedPtr costmap_sub_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
    rclcpp::Publisher<nav_msgs::msg::OccupancyGrid>::SharedPtr map_pub_;
	rclcpp::TimerBase::SharedPtr timer_;

	// Callbacks
	void costmap_callback(nav_msgs::msg::OccupancyGrid::SharedPtr costmap);
	void odom_callback(nav_msgs::msg::Odometry::SharedPtr odom_msg);
	void updateMap();

	// Flags
	double last_x = -100;
	double last_y = -100;
    const double distance_threshold;
    bool costmap_updated_ = false;
    nav_msgs::msg::OccupancyGrid::SharedPtr latest_costmap_;
    bool should_update_map_ = false;
	
};

#endif 
