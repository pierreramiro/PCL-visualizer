#include "pclviewer.h"
#include "ui_pclviewer.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"
#include <time.h>
#if VTK_MAJOR_VERSION > 8
#include <vtkGenericOpenGLRenderWindow.h>
#endif
//#include "voxel_reconstruction.h"


//aditional functions

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


PCLViewer::PCLViewer (QWidget *parent) :
  QMainWindow (parent),
  ui (new Ui::PCLViewer)
{
  ui->setupUi (this);
  //Set Title
  this->setWindowTitle ("TUMI Visualizer");
  /*********************************************************/
  /************* Load the cloud from a .csv file ***********/
  /*********************************************************/
  cloud.reset (new PointCloudTxyz);
  // The number of points in the cloud
  cloud->resize (16384*6);
  // Fill the cloud with some points
  //aqui podemos poner la nube de puntos
  FILE* archivo;
  char buffer[400];
  char* token;
#define testingUI 1
#if  testingUI==0
  archivo = fopen("home/tumi/GUI/bunny/MinaData.csv", "r+");
  //Saltamos la primera línea
  double* Point_Cloud = (double*)malloc(n_total_points * 3 *sizeof(double));
  fgets(buffer,sizeof(buffer),archivo);
  for (unsigned int i = 0; i < n_total_points; i++){
      fgets(buffer,sizeof(buffer),archivo);
      token = strtok(buffer,",");
      Point_Cloud[i*3+0]=atof(token);
      token = strtok(NULL,",");
      Point_Cloud[i*3+1]=atof(token);
      token = strtok(NULL,",\n");
      Point_Cloud[i*3+2]=atof(token);
  }    
  fclose(archivo);

#endif 
  /*************************************************************/
  /************* Generate the surface reconstruction ***********/
  /*************************************************************/
#if testingUI==1

  triangles.reset (new pcl::PolygonMesh);
  //Downsample data Mina
  triangles->polygons.resize(7898);//change
  vex.vertices.resize(3);
  cloud->resize(3969);//change
  // archivo = fopen("/home/catolica/Documents/Github/PCL-visualizer/viewer/src/downsamp_cloud.csv", "r+");
  archivo = fopen("/home/tumi/GUI/bunny/downsamp_cloud.csv", "r+");
  for (auto& point: *cloud){
    fgets(buffer,sizeof(buffer),archivo);
    token = strtok(buffer," ");
    point.x=atof(token);
    token = strtok(NULL," ");
    point.y=atof(token);
    token = strtok(NULL," \n");
    point.z=atof(token);
  }
  pcl::toPCLPointCloud2(*cloud, triangles->cloud);
  // archivo = fopen("/home/catolica/Documents/Github/PCL-visualizer/viewer/src/downsamp_surf.csv", "r+");
  archivo = fopen("/home/tumi/GUI/bunny/downsamp_surf.csv", "r+");
  for (unsigned int i=0; i<7898; ++i)
  { 
    fgets(buffer,sizeof(buffer),archivo);
    token = strtok(buffer," ");
    vex.vertices[0]=atoi(token);
    token = strtok(NULL," ");
    vex.vertices[1]=atoi(token);
    token = strtok(NULL," \n");
    vex.vertices[2]=atoi(token);
    //vex.vertices[3]=vex.vertices[0];
    triangles->polygons[i]= vex;
  }
#else
  /**************************************************/
  /*************    Dowmsapled default    ***********/
  /**************************************************/
  //Voxel downsampling
  double *downsampled_cloud;
  int *downsampled_surface;
  int num_points_downsamp=0, num_triangles_downsamp=0;
  Voxel_Reconstruction(Point_Cloud,downsampled_cloud,downsampled_surface, &num_points_downsamp, &num_triangles_downsamp);

  //Transform data to PCL PolygonMesh type
  toPCLPolygonMesh(downsampled_cloud,downsampled_surface,triangles,num_points_downsamp,num_triangles_downsamp);

#endif
  /******************************************************/
  /**************** Set up the QVTK window **************/
  /******************************************************/
#if VTK_MAJOR_VERSION > 8
  auto renderer = vtkSmartPointer<vtkRenderer>::New();
  auto renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
  renderWindow->AddRenderer(renderer);
  viewer.reset(new pcl::visualization::PCLVisualizer(renderer, renderWindow, "viewer", false));
  ui->qvtkWidget->setRenderWindow(viewer->getRenderWindow());
  viewer->setupInteractor(ui->qvtkWidget->interactor(), ui->qvtkWidget->renderWindow());
#else
  viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
  ui->qvtkWidget->SetRenderWindow(viewer->getRenderWindow());
  viewer->setupInteractor(ui->qvtkWidget->GetInteractor(), ui->qvtkWidget->GetRenderWindow());
#endif
  //set color to background
  viewer->setBackgroundColor (0, 0, 0);
  //add point cloud to visualizer
  viewer->addPointCloud (cloud, "cloud");
  viewer->addPolygonMesh(*triangles,"mesh");
  viewer->removePolygonMesh ("mesh");
  //set point size of the cloud to '2'
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pointsize, "cloud");
  //Reset the camera of the viewer and refresh the view 
  viewer->resetCamera ();
  refreshView();
}


/***************************************************************************************************************/


/********************************************************/
/******************* Viewer Functions *******************/
/********************************************************/
void
PCLViewer::refreshView()
{
#if VTK_MAJOR_VERSION > 8
  ui->qvtkWidget->renderWindow()->Render();
#else
  ui->qvtkWidget->update();
#endif
}

PCLViewer::~PCLViewer ()
{
  delete ui;
}
/*******************************************************/
/****************** Background color *******************/
/*******************************************************/
void PCLViewer::on_pushButton_yellow_pressed()
{
  viewer->setBackgroundColor (237, 212, 0);
  refreshView();
}

void PCLViewer::on_pushButton_black_pressed()
{
viewer->setBackgroundColor (0, 0, 0);
refreshView();
}

void PCLViewer::on_pushButton_white_pressed()
{
  viewer->setBackgroundColor (255, 255, 255);
  refreshView();
}

void PCLViewer::on_pushButton_red_pressed()
{
  viewer->setBackgroundColor (204, 0, 0);
  refreshView();
}

void PCLViewer::on_pushButton_blue_pressed()
{
  viewer->setBackgroundColor (0, 0, 255);
  refreshView();
}
/******************************************************/
/*******************   Point Size   *******************/
/******************************************************/
void PCLViewer::on_horizontalSlider_PointSize_valueChanged(int value)
{
  //Display value
  pointsize=value;
  ui->lcdnumber_PointSize->display(pointsize);
  //Set the point size to the cloud
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pointsize, "cloud");
  //refresh the visualizer
  refreshView();
}
/*************************************************************/
/*******************   Point Cloud Viewer   ******************/
/*************************************************************/
void PCLViewer::on_pushButton_PointCloud_pressed()
{
  if (!ShowingPointCloud){
    viewer->removePolygonMesh("mesh");
    viewer->addPointCloud (cloud,"cloud");
    ShowingPointCloud=true;
    viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pointsize, "cloud");
    refreshView();
  }
}
/*********************************************************/
/*******************   Surface Viewer   ******************/
/*********************************************************/
void PCLViewer::on_pushButton_Surface_pressed()
{
  if(ShowingPointCloud){
    viewer->removePointCloud("cloud");
    viewer->addPolygonMesh (*triangles,"mesh");
    ShowingPointCloud=false;
    refreshView();
  }
}
