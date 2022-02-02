#pragma once

#include <iostream>

// Qt
#include <QMainWindow>

// Point Cloud Library
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/io/pcd_io.h>
#include <pcl/conversions.h>
#include <pcl/search/kdtree.h> // for KdTree
#include <pcl/features/normal_3d.h>
#include <pcl/surface/gp3.h>
#include <pcl/Vertices.h>

typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointCloud<PointT> PointCloudT;
typedef pcl::PointXYZ PointTxyz;


namespace Ui
{
  class PCLViewer;
}

class PCLViewer : public QMainWindow
{
  Q_OBJECT

public:
  explicit PCLViewer (QWidget *parent = 0);
  ~PCLViewer ();

public Q_SLOTS:
 
protected:
  void
  refreshView();

  pcl::visualization::PCLVisualizer::Ptr viewer;
  PointCloudT::Ptr cloud;
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloudDS;


  unsigned int red;
  unsigned int green;
  unsigned int blue;

private slots:

  void on_pushButton_yellow_pressed();

  void on_pushButton_black_pressed();

  void on_pushButton_white_pressed();

  void on_pushButton_red_pressed();

  void on_pushButton_blue_pressed();

  void on_horizontalSlider_PointSize_valueChanged(int value);

  void on_pushButton_PointCloud_pressed();

  void on_pushButton_Surface_pressed();

private:
  Ui::PCLViewer *ui;
};
