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
  this->setWindowTitle ("TUMI Visualizers");

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

  // Connect "random" button and the function
  connect (ui->pushButton_random,  SIGNAL (clicked ()), this, SLOT (on_pushButton_random_pressed ()));

  // Connect R,G,B sliders and their functions
  connect (ui->horizontalSlider_R, SIGNAL (valueChanged (int)), this, SLOT (redSliderValueChanged (int)));
  connect (ui->horizontalSlider_G, SIGNAL (valueChanged (int)), this, SLOT (greenSliderValueChanged (int)));
  connect (ui->horizontalSlider_B, SIGNAL (valueChanged (int)), this, SLOT (blueSliderValueChanged (int)));
  connect (ui->horizontalSlider_R, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));
  connect (ui->horizontalSlider_G, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));
  connect (ui->horizontalSlider_B, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));

  // Connect point size slider
  connect (ui->horizontalSlider_p, SIGNAL (valueChanged (int)), this, SLOT (pSliderValueChanged (int)));

  //Additional buttons
  connect (ui->pushButton_clear, SIGNAL (pressed()), this, SLOT (on_pushButton_clear_pressed ()));
  connect (ui->pushButton_add, SIGNAL (pressed()), this, SLOT (on_pushButton_add_pressed ()));
  //Colour buttons
  connect (ui->pushButton_blackbackground, SIGNAL (pressed()), this, SLOT (on_pushButton_blackbackground_pressed ()));
  connect (ui->pushButton_yellowbackground, SIGNAL (pressed()), this, SLOT (on_pushButton_yellowbackground_pressed ()));
  connect (ui->pushButton_redbackground, SIGNAL (pressed()), this, SLOT (on_pushButton_redbackground_pressed ()));
  connect (ui->pushButton_whitebackground, SIGNAL (pressed()), this, SLOT (on_pushButton_whitebackground_pressed ()));
  connect (ui->pushButton_bluebackground, SIGNAL (pressed()), this, SLOT (on_pushButton_bluebackground_pressed ()));


  //ponemos color
  viewer->setBackgroundColor (0, 0, 255);
  //configuramos para poder hacer 3d
  //viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "cloud");

  viewer->addPointCloud (cloud, "cloud");
  pSliderValueChanged (2);
  viewer->resetCamera ();
  
  refreshView();
}

void
PCLViewer::RGBsliderReleased ()
{
  // Set the new color
  for (auto& point: *cloud)
  {
    point.r = red;
    point.g = green;
    point.b = blue;
  }
  viewer->updatePointCloud (cloud, "cloud");
  refreshView();
}

void
PCLViewer::pSliderValueChanged (int value)
{
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, value, "cloud");
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

void
PCLViewer::redSliderValueChanged (int value)
{
  red = value;
  printf ("redSliderValueChanged: [%d|%d|%d]\n", red, green, blue);
}

void
PCLViewer::greenSliderValueChanged (int value)
{
  green = value;
  printf ("greenSliderValueChanged: [%d|%d|%d]\n", red, green, blue);
}

void
PCLViewer::blueSliderValueChanged (int value)
{
  blue = value;
  printf("blueSliderValueChanged: [%d|%d|%d]\n", red, green, blue);
}

PCLViewer::~PCLViewer ()
{
  delete ui;
}

void PCLViewer::on_pushButton_random_pressed()
{
    printf ("Random button was pressed\n");

    // Set the new color
    for (auto& point: *cloud)
    {
      point.r = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
      point.g = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
      point.b = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
    }

    viewer->updatePointCloud (cloud, "cloud");
    refreshView();
}


void PCLViewer::on_pushButton_clear_pressed()
{
    viewer->removePointCloud();
    refreshView();
}

void PCLViewer::on_pushButton_add_pressed()
{
    viewer->addPointCloud (cloud,"cloud");
    refreshView();
}

void PCLViewer::on_pushButton_blackbackground_pressed()
{
    viewer->setBackgroundColor (0, 0, 0);
    refreshView();
}

void PCLViewer::on_pushButton_yellowbackground_pressed()
{
    viewer->setBackgroundColor (237, 212, 0);
    refreshView();
}

void PCLViewer::on_pushButton_redbackground_pressed()
{
    viewer->setBackgroundColor (204, 0, 0);
    refreshView();
}

void PCLViewer::on_pushButton_whitebackground_pressed()
{
    viewer->setBackgroundColor (255, 255, 255);
    refreshView();
}

void PCLViewer::on_pushButton_bluebackground_pressed()
{
    viewer->setBackgroundColor (0, 0, 255);
    refreshView();
}
