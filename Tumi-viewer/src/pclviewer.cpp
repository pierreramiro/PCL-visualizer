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

PCLViewer::PCLViewer (QWidget *parent) :
  QMainWindow (parent),
  ui (new Ui::PCLViewer)
{
  ui->setupUi (this);
  this->setWindowTitle ("TUMI Visualizer");

  // Setup the cloud pointer
  cloud.reset (new PointCloudT);
  // The number of points in the cloud
  //cloud->resize (200);
  cloud->resize (16384*6);
  // The default color
  red   = 128;
  green = 128;
  blue  = 128;

  // Fill the cloud with some points
  //aqui podemos poner la nube de puntos
  FILE* archivo;
  archivo = fopen("../src/MinaData.csv", "r+");
  char buffer[400];
  char* token;
  //Saltamos la primera línea
  fgets(buffer,sizeof(buffer),archivo);
  for (auto& point: *cloud)
  {
    /*
    point.x = 1024 * rand () / (RAND_MAX + 1.0f);
    point.y = 1024 * rand () / (RAND_MAX + 1.0f);
    point.z = 1024 * rand () / (RAND_MAX + 1.0f);
    */
    fgets(buffer,sizeof(buffer),archivo);
    token = strtok(buffer,",");
    point.x=atof(token);
    token = strtok(NULL,",");
    point.y=atof(token);
    token = strtok(NULL,",\n");
    point.z=atof(token);

    point.r = red;
    point.g = green;
    point.b = blue;
  }
  fclose(archivo);
  // Set up the QVTK window
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
  //ponemos color
  viewer->setBackgroundColor (0, 0, 0);
  //configuramos para poder hacer 3d
  //viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "cloud");

  viewer->addPointCloud (cloud, "cloud");
  viewer->resetCamera ();

  refreshView();
}

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

void PCLViewer::on_horizontalSlider_PointSize_valueChanged(int value)
{
    ui->lcdnumber_PointSize->display(value);
}

void PCLViewer::on_pushButton_PointCloud_pressed()
{

}

void PCLViewer::on_pushButton_Surface_pressed()
{

}
