#pragma once

#include <iostream>

// Qt
#include <QMainWindow>

// Point Cloud Library
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>

typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

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

  void
  RGBsliderReleased ();

  void
  pSliderValueChanged (int value);

  void
  redSliderValueChanged (int value);

  void
  greenSliderValueChanged (int value);

  void
  blueSliderValueChanged (int value);

protected:
  void
  refreshView();

  pcl::visualization::PCLVisualizer::Ptr viewer;
  PointCloudT::Ptr cloud;

  unsigned int red;
  unsigned int green;
  unsigned int blue;

private slots:
  void on_pushButton_random_pressed();

  void on_pushButton_clear_pressed();

  void on_pushButton_add_pressed();

  void on_pushButton_blackbackground_pressed();

  void on_pushButton_yellowbackground_pressed();

  void on_pushButton_redbackground_pressed();

  void on_pushButton_whitebackground_pressed();

  void on_pushButton_bluebackground_pressed();

private:
  Ui::PCLViewer *ui;
};
