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
  Donut1.reset (new PointCloudT);
  Donut2.reset (new PointCloudT);
  Donut3.reset (new PointCloudT);
  Donut4.reset (new PointCloudT);
  Donut5.reset (new PointCloudT);
  Donut6.reset (new PointCloudT);

  // The number of points in the cloud
  cloud->resize (16384*6);
  Donut1->resize (16384);
  Donut2->resize (16384);
  Donut3->resize (16384);
  Donut4->resize (16384);
  Donut5->resize (16384);
  Donut6->resize (16384);
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
  for (auto& point: *Donut1){
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
  for (auto& point: *Donut2){
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
  for (auto& point: *Donut3){
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
  for (auto& point: *Donut4){
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
  for (auto& point: *Donut5){
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
  for (auto& point: *Donut6){
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
  archivo = fopen("../src/MinaData.csv", "r+");
  fgets(buffer,sizeof(buffer),archivo);
  for (auto& point: *cloud){
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
  //Add vertices and Faces
  /*archivo = fopen("../src/MinaTriangleMesh.csv", "r+");
  fgets(buffer,sizeof(buffer),archivo);
  for (unsigned int i=0; i<95143; ++i)
  { 
    fgets(buffer,sizeof(buffer),archivo);
    token = strtok(buffer,",");
    vi.push_back (mesh.addVertex (MyVertexData (atoi(token))));
    token = strtok(NULL,",");
    vi.push_back (mesh.addVertex (MyVertexData (atoi(token))));
    token = strtok(NULL,",\n");
    vi.push_back (mesh.addVertex (MyVertexData (atoi(token))));
    mesh.addFace (vi [i*3], vi [i*3+1], vi [i*3+2]);
  }
  */
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

  /*
  //Additional buttons
  connect (ui->pushButton_clear, SIGNAL (pressed()), this, SLOT (on_pushButton_clear_pressed ()));
  //connect (ui->pushButton_add, SIGNAL (pressed()), this, SLOT (on_pushButton_add_pressed ()));
  //Colour buttons
  connect (ui->pushButton_blackbackground, SIGNAL (pressed()), this, SLOT (on_pushButton_blackbackground_pressed ()));
  connect (ui->pushButton_yellowbackground, SIGNAL (pressed()), this, SLOT (on_pushButton_yellowbackground_pressed ()));
  connect (ui->pushButton_redbackground, SIGNAL (pressed()), this, SLOT (on_pushButton_redbackground_pressed ()));
  connect (ui->pushButton_whitebackground, SIGNAL (pressed()), this, SLOT (on_pushButton_whitebackground_pressed ()));
  connect (ui->pushButton_bluebackground, SIGNAL (pressed()), this, SLOT (on_pushButton_bluebackground_pressed ()));
  */

  //ponemos color
  viewer->setBackgroundColor (0, 0, 0);
  //configuramos para poder hacer 3d
  viewer->addPointCloud (cloud, "cloud");
  //viewer->addPolygonMesh (mesh,"polygon");
  viewer->addPolygon<PointT>(Donut1);
  //Le ponemos un valor al tamaño de los puntos
  pSliderValueChanged (1);
  //Reseteamos el view de la camara
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
  for (auto& point: *Donut1)
  {
    point.r = red;
    point.g = green;
    point.b = blue;
  }
  for (auto& point: *Donut2)
  {
    point.r = red;
    point.g = green;
    point.b = blue;
  }
  for (auto& point: *Donut3)
  {
    point.r = red;
    point.g = green;
    point.b = blue;
  }
  for (auto& point: *Donut4)
  {
    point.r = red;
    point.g = green;
    point.b = blue;
  }
  for (auto& point: *Donut5)
  {
    point.r = red;
    point.g = green;
    point.b = blue;
  }
  for (auto& point: *Donut6)
  {
    point.r = red;
    point.g = green;
    point.b = blue;
  }

  viewer->updatePointCloud (cloud, "cloud");
  viewer->updatePointCloud (Donut1, "cloud1");
  viewer->updatePointCloud (Donut2, "cloud2");
  viewer->updatePointCloud (Donut3, "cloud3");
  viewer->updatePointCloud (Donut4, "cloud4");
  viewer->updatePointCloud (Donut5, "cloud5");
  viewer->updatePointCloud (Donut6, "cloud6");
  refreshView();
}

void
PCLViewer::pSliderValueChanged (int value)
{
  pointSize=value;
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pointSize, "cloud");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pointSize, "cloud1");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pointSize, "cloud2");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pointSize, "cloud3");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pointSize, "cloud4");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pointSize, "cloud5");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pointSize, "cloud6");
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
    for (auto& point: *Donut1)
    {
      point.r = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
      point.g = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
      point.b = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
    }
    for (auto& point: *Donut2)
    {
      point.r = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
      point.g = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
      point.b = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
    }
    for (auto& point: *Donut3)
    {
      point.r = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
      point.g = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
      point.b = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
    }
    for (auto& point: *Donut4)
    {
      point.r = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
      point.g = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
      point.b = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
    }
    for (auto& point: *Donut5)
    {
      point.r = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
      point.g = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
      point.b = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
    }
    for (auto& point: *Donut6)
    {
      point.r = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
      point.g = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
      point.b = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
    }

    viewer->updatePointCloud (cloud, "cloud");
    viewer->updatePointCloud (Donut1, "cloud1");
    viewer->updatePointCloud (Donut2, "cloud2");
    viewer->updatePointCloud (Donut3, "cloud3");
    viewer->updatePointCloud (Donut4, "cloud4");
    viewer->updatePointCloud (Donut5, "cloud5");
    viewer->updatePointCloud (Donut6, "cloud6");
    refreshView();
}


void PCLViewer::on_pushButton_clear_pressed()
{
  counter=0;
    viewer->removePointCloud("cloud");
    viewer->removePointCloud("cloud1");
    viewer->removePointCloud("cloud2");
    viewer->removePointCloud("cloud3");
    viewer->removePointCloud("cloud4");
    viewer->removePointCloud("cloud5");
    viewer->removePointCloud("cloud6");
    refreshView();
}

void PCLViewer::on_pushButton_add_pressed()
{
  switch(counter){
    case 0:
      viewer->addPointCloud (Donut1,"cloud1");
      counter++;
      break;
    case 1:
      viewer->addPointCloud (Donut2,"cloud2");
      counter++;
      break;
    case 2:
      viewer->addPointCloud (Donut3,"cloud3");
      counter++;
      break;
    case 3:
      viewer->addPointCloud (Donut4,"cloud4");
      counter++;
      break;
    case 4:
      viewer->addPointCloud (Donut5,"cloud5");
      counter++;
      break;
    case 5:
      viewer->addPointCloud (Donut6,"cloud6");
      break;
    default:
      //counter=1;
      break;
  }
  printf("counter: %d\n",counter);
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pointSize, "cloud1");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pointSize, "cloud2");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pointSize, "cloud3");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pointSize, "cloud4");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pointSize, "cloud5");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, pointSize, "cloud6");
  
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
