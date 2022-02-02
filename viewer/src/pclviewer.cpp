#include "pclviewer.h"
#include "ui_pclviewer.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "math.h"
#include <time.h>
#include <iostream>
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
  archivo = fopen("/home/catolica/Documents/Github/PCL-visualizer/viewer/src/MinaData.csv", "r+");
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
  archivo = fopen("/home/catolica/Documents/Github/PCL-visualizer/viewer/src/MinaData.csv", "r+");
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
  
#define MESH_OPTION 4
#if MESH_OPTION==0
  //Original data Mina
  mesh.polygons.resize(95143);
  vex.vertices.resize(3);
  cloudXYZ.resize(16384*6);
  for (size_t i = 0; i < 16384*6; i++) {
      cloudXYZ[i].x = cloud->points[i].x;
      cloudXYZ[i].y = cloud->points[i].y;
      cloudXYZ[i].z = cloud->points[i].z;
  }
  pcl::toPCLPointCloud2(cloudXYZ, mesh.cloud);
  archivo = fopen("/home/catolica/Documents/Github/PCL-visualizer/viewer/src/MinaTriangleMesh.csv", "r+");
  fgets(buffer,sizeof(buffer),archivo);
  for (unsigned int i=0; i<95143; ++i)
  { 
    fgets(buffer,sizeof(buffer),archivo);
    token = strtok(buffer,",");
    vex.vertices[0]=atoi(token);
    token = strtok(NULL,",");
    vex.vertices[1]=atoi(token);
    token = strtok(NULL,",\n");
    vex.vertices[2]=atoi(token);
    mesh.polygons[i]= vex;
  }
#elif MESH_OPTION==1
  //Downsample data Mina
  mesh.polygons.resize(7898);
  vex.vertices.resize(3);
  cloudXYZ.resize(3969);
  archivo = fopen("/home/catolica/Documents/Github/PCL-visualizer/viewer/src/downsamp_cloud.csv", "r+");
  for (size_t i = 0; i < 3969; i++) {
    fgets(buffer,sizeof(buffer),archivo);
    token = strtok(buffer," ");
    cloudXYZ[i].x = atof(token)/1000;
    token = strtok(NULL," ");
    cloudXYZ[i].y = atof(token)/1000;
    token = strtok(NULL," \n");
    cloudXYZ[i].z = atof(token)/1000;    
  }
  pcl::toPCLPointCloud2(cloudXYZ, mesh.cloud);
  archivo = fopen("/home/catolica/Documents/Github/PCL-visualizer/viewer/src/downsamp_surf.csv", "r+");
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
    mesh.polygons[i]= vex;
  }
#elif MESH_OPTION==2
  //Downsampled with normals
  cloudDS.reset(new  pcl::PointCloud<pcl::PointXYZ>);
  cloudDS->resize(3969);
  archivo = fopen("/home/catolica/Documents/Github/PCL-visualizer/viewer/src/downsamp_cloud.csv", "r+"); 
  for (auto& point: *cloudDS){
    fgets(buffer,sizeof(buffer),archivo);
    token = strtok(buffer," ");
    point.x=atof(token);
    token = strtok(NULL," ");
    point.y=atof(token);
    token = strtok(NULL," \n");
    point.z=atof(token);
  }
  // Normal estimation*
  pcl::NormalEstimation<PointTxyz, pcl::Normal> n;
  pcl::PointCloud<pcl::Normal>::Ptr normals (new pcl::PointCloud<pcl::Normal>);
  pcl::search::KdTree<PointTxyz>::Ptr tree (new pcl::search::KdTree<PointTxyz>);
  tree->setInputCloud (cloudDS);
  n.setInputCloud (cloudDS);
  n.setSearchMethod (tree);
  n.setKSearch (20);
  n.compute (*normals);
  //* normals should not contain the point normals + surface curvatures

  // Concatenate the XYZ and normal fields*
  pcl::PointCloud<pcl::PointNormal>::Ptr cloud_with_normals (new pcl::PointCloud<pcl::PointNormal>);
  pcl::concatenateFields (*cloudDS, *normals, *cloud_with_normals);
  //* cloud_with_normals = cloud + normals

  mesh.polygons.resize(7898);
  pcl::toPCLPointCloud2(*cloud_with_normals, mesh.cloud);
  vex.vertices.resize(4);
  archivo = fopen("/home/catolica/Documents/Github/PCL-visualizer/viewer/src/downsamp_surf.csv", "r+");
  for (unsigned int i=0; i<7898; ++i)
  { 
    fgets(buffer,sizeof(buffer),archivo);
    token = strtok(buffer," ");
    vex.vertices[0]=atoi(token);
    token = strtok(NULL," ");
    vex.vertices[1]=atoi(token);
    token = strtok(NULL," \n");
    vex.vertices[2]=atoi(token);
    vex.vertices[3]=vex.vertices[0];
    mesh.polygons[i]= vex;
  }
#elif MESH_OPTION ==3
//KdTree downsample .csv
  cloudDS.reset(new  pcl::PointCloud<pcl::PointXYZ>);
  cloudDS->resize(3969);
  archivo = fopen("/home/catolica/Documents/Github/PCL-visualizer/viewer/src/downsamp_cloud.csv", "r+"); 
  for (auto& point: *cloudDS){
    fgets(buffer,sizeof(buffer),archivo);
    token = strtok(buffer," ");
    point.x=atof(token)/1000;
    token = strtok(NULL," ");
    point.y=atof(token)/1000;
    token = strtok(NULL," \n");
    point.z=atof(token)/1000;
  }
  // Normal estimation*
  pcl::NormalEstimation<PointTxyz, pcl::Normal> n;
  pcl::PointCloud<pcl::Normal>::Ptr normals (new pcl::PointCloud<pcl::Normal>);
  pcl::search::KdTree<PointTxyz>::Ptr tree (new pcl::search::KdTree<PointTxyz>);
  tree->setInputCloud (cloudDS);
  n.setInputCloud (cloudDS);
  n.setSearchMethod (tree);
  n.setKSearch (20);
  n.compute (*normals);
  //* normals should not contain the point normals + surface curvatures

  // Concatenate the XYZ and normal fields*
  pcl::PointCloud<pcl::PointNormal>::Ptr cloud_with_normals (new pcl::PointCloud<pcl::PointNormal>);
  pcl::concatenateFields (*cloudDS, *normals, *cloud_with_normals);
  //* cloud_with_normals = cloud + normals

  // Create search tree*
  pcl::search::KdTree<pcl::PointNormal>::Ptr tree2 (new pcl::search::KdTree<pcl::PointNormal>);
  tree2->setInputCloud (cloud_with_normals);

  // Initialize objects
  pcl::GreedyProjectionTriangulation<pcl::PointNormal> gp3;
  //pcl::PolygonMesh triangles;

  // Set the maximum distance between connected points (maximum edge length)
  gp3.setSearchRadius (50);

  // Set typical values for the parameters
  gp3.setMu (2.5);
  gp3.setMaximumNearestNeighbors (200);
  gp3.setMaximumSurfaceAngle(M_PI/4); // 45 degrees
  gp3.setMinimumAngle(M_PI/18); // 10 degrees
  gp3.setMaximumAngle(2*M_PI/3); // 120 degrees
  gp3.setNormalConsistency(false);

  // Get result
  gp3.setInputCloud (cloud_with_normals);
  gp3.setSearchMethod (tree2);
  gp3.reconstruct (mesh);
#else

  cloudDS.reset (new pcl::PointCloud<PointTxyz>);
  if (pcl::io::loadPCDFile<PointTxyz> ("/home/catolica/Documents/Github/PCL-visualizer/viewer/src/mine.pcd", *cloudDS) == -1) //* load the file
  {
    PCL_ERROR ("Couldn't read file \n");
  }
  for (auto& point: *cloudDS)
  {
    // cout << point.x << ", " << point.y << ", " << point.z << " | ";

    point.x = point.x/1000;
    point.y = point.y/1000;
    point.z = point.z/1000;

    // point.a = 128;

    // cout << int(point.r) << ", " << int(point.g) << ", " << int(point.b) << std::endl;
  }
  // Normal estimation*
  pcl::NormalEstimation<PointTxyz, pcl::Normal> n;
  pcl::PointCloud<pcl::Normal>::Ptr normals (new pcl::PointCloud<pcl::Normal>);
  pcl::search::KdTree<PointTxyz>::Ptr tree (new pcl::search::KdTree<PointTxyz>);
  tree->setInputCloud (cloudDS);
  n.setInputCloud (cloudDS);
  n.setSearchMethod (tree);
  n.setKSearch (20);
  n.compute (*normals);
  //* normals should not contain the point normals + surface curvatures

  // Concatenate the XYZ and normal fields*
  pcl::PointCloud<pcl::PointNormal>::Ptr cloud_with_normals (new pcl::PointCloud<pcl::PointNormal>);
  pcl::concatenateFields (*cloudDS, *normals, *cloud_with_normals);
  //* cloud_with_normals = cloud + normals

  // Create search tree*
  pcl::search::KdTree<pcl::PointNormal>::Ptr tree2 (new pcl::search::KdTree<pcl::PointNormal>);
  tree2->setInputCloud (cloud_with_normals);

  // Initialize objects
  pcl::GreedyProjectionTriangulation<pcl::PointNormal> gp3;
  //pcl::PolygonMesh triangles;

  // Set the maximum distance between connected points (maximum edge length)
  gp3.setSearchRadius (50);

  // Set typical values for the parameters
  gp3.setMu (2.5);
  gp3.setMaximumNearestNeighbors (200);
  gp3.setMaximumSurfaceAngle(M_PI/4); // 45 degrees
  gp3.setMinimumAngle(M_PI/18); // 10 degrees
  gp3.setMaximumAngle(2*M_PI/3); // 120 degrees
  gp3.setNormalConsistency(false);

  // Get result
  gp3.setInputCloud (cloud_with_normals);
  gp3.setSearchMethod (tree2);
  gp3.reconstruct (mesh);

  

#endif

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
  //viewer->addPointCloud (cloud, "cloud");
  //viewer->addPolygon<PointT>(Donut1);
  viewer->addPolygonMesh (mesh,"polygon");
 //Le ponemos un valor al tamaño de los puntos
  pSliderValueChanged (4);
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
