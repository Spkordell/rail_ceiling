#ifndef CEILING_LAYER_H_
#define CEILING_LAYER_H_

#include <ros/ros.h>
#include <boost/algorithm/string.hpp>
#include <costmap_2d/layer.h>
#include <costmap_2d/layered_costmap.h>
#include <costmap_2d/GenericPluginConfig.h>
#include <dynamic_reconfigure/server.h>
#include <nav_msgs/OccupancyGrid.h>

namespace ceiling_layer_namespace
{
  class CeilingLayer : public costmap_2d::Layer, public costmap_2d::Costmap2D
  {
  public:
    CeilingLayer();

    virtual void onInitialize();
    virtual void updateBounds(double origin_x, double origin_y, double origin_yaw, double* min_x, double* min_y, double* max_x, double* max_y);
    virtual void updateCosts(costmap_2d::Costmap2D& master_grid, int min_i, int min_j, int max_i, int max_j);
    bool isDiscretized()
    {
      return true;
    }

    virtual void matchSize();

  private:
    ros::Subscriber map_in; /*!< map_in topic */
    nav_msgs::OccupancyGrid obstacleMap; /*!< map used for determining parameters of output map */
    bool mapReceived; /*!< true when a map has been received */
    std::string map_topic; /*! < the topic to get the ar map from */

    /*!
     * callback for receiving the obstacle map
     * \param map The map
     */
    void map_in_cback(const nav_msgs::OccupancyGrid::ConstPtr& map);

    void reconfigureCB(costmap_2d::GenericPluginConfig &config, uint32_t level);
    dynamic_reconfigure::Server<costmap_2d::GenericPluginConfig> *dsrv_;
  };
}

#endif //CEILING_LAYER_H_
