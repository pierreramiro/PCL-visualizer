#pragma once

#include <iostream>

// Qt
#include <QMainWindow>

// Point Cloud Library
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/geometry/polygon_mesh.h>
#include <pcl/io/vtk_lib_io.h>

typedef pcl::PointXYZRGBA PointT;
typedef pcl::PointCloud<PointT> PointCloudT;

namespace Ui
{
  class PCLViewer;
}

class MyVertexData
{
  public:

    MyVertexData (const int id = -1) : id_ (id) {}

    int  id () const {return (id_);}
    int& id ()       {return (id_);}

  private:

    int id_;
};

// Declare the mesh.
using Mesh = pcl::geometry::PolygonMesh<pcl::geometry::DefaultMeshTraits<MyVertexData> >;
using VertexIndex = Mesh::VertexIndex;
using VertexIndices = Mesh::VertexIndices;


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
  pcl::PolygonMesh mesh;
  VertexIndices vi;

  PointCloudT::Ptr cloud;
  PointCloudT::Ptr Donut1;
  PointCloudT::Ptr Donut2;
  PointCloudT::Ptr Donut3;
  PointCloudT::Ptr Donut4;
  PointCloudT::Ptr Donut5;
  PointCloudT::Ptr Donut6;


  unsigned int red;
  unsigned int green;
  unsigned int blue;
  int counter=6;
  int pointSize;

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
