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

//define types
typedef pcl::PointXYZ PointTxyz;
typedef pcl::PointCloud<PointTxyz> PointCloudTxyz;
typedef pcl::PointXYZ PointTxyzrgba;
typedef pcl::PointCloud<PointTxyzrgba> PointCloudTxyzrgba;


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
  
  /****************************************************************/
  /*******************   Variables definition   *******************/
  /****************************************************************/
  pcl::visualization::PCLVisualizer::Ptr viewer;
  PointCloudTxyz::Ptr cloud;
  pcl::PolygonMesh::Ptr triangles;
  pcl::Vertices vex;
  int pointsize=2;

  //Define some flags
  bool ShowingPointCloud =true;  
  /****************************************************************/
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

//aditional functions
/*
void toPCLPolygonMesh(double* downsampled_cloud,int* downsampled_surface,pcl::PolygonMesh::Ptr mesh,int num_points_downsamp,int num_triangles_downsamp){

  pcl::Vertices Vertex;
  Vertex.vertices.resize(3);
  (*mesh).polygons.resize(num_triangles_downsamp);
  pcl::PointCloud<pcl::PointXYZ>::Ptr TempCloud;
  TempCloud->resize(num_points_downsamp);
  //double::Ptr to pcl::Point::Ptr
  unsigned int z=0;
  for (auto& point: *TempCloud){
    point.x=downsampled_cloud[z*3+0];
    point.y=downsampled_cloud[z*3+1];
    point.z=downsampled_cloud[z*3+2];
    z++;
  }
  pcl::toPCLPointCloud2(*TempCloud, (*mesh).cloud);
  //int::Ptr to pcl:Vertices. then attacht to pcl::PolygonMesh type
  for (z=0;z<num_triangles_downsamp;z++){
    Vertex.vertices[0]=downsampled_surface[z*3+0];
    Vertex.vertices[1]=downsampled_surface[z*3+1];
    Vertex.vertices[2]=downsampled_surface[z*3+2];
    (*mesh).polygons[z]= Vertex;
  }
}
*/
