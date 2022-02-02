#include "pclviewer.h"
#include "ui_pclviewer.h"

#if VTK_MAJOR_VERSION > 8
#include <vtkGenericOpenGLRenderWindow.h>
#endif

PCLViewer::PCLViewer (QWidget *parent) :
  QMainWindow (parent),
  ui (new Ui::PCLViewer)
{
  ui->setupUi (this);
  this->setWindowTitle ("PCL viewer");

  // Setup the cloud pointer
  cloud.reset (new PointCloudT);
  // PointCloudT::Ptr cloud (new PointCloudT);

  // if (pcl::io::loadPCDFile<PointT> ("/home/tumi/GUI/bunny/mine.pcd", *cloud) == -1) //* load the file
  // {
  //   PCL_ERROR ("Couldn't read file bunny_cloud.pcd \n");
  // }
  // std::cout << "Loaded "
  //           << cloud->width * cloud->height
  //           << " data points from bunny_cloud.pcd with the following fields: "
  //           << std::endl;

  // // Fill the cloud with some points
  // for (auto& point: *cloud)
  // {
  //   // cout << point.x << ", " << point.y << ", " << point.z << " | ";

  //   point.x = point.x/1000;
  //   point.y = point.y/1000;
  //   point.z = point.z/1000;

  //   // point.a = 128;

  //   // cout << int(point.r) << ", " << int(point.g) << ", " << int(point.b) << std::endl;
  // }

  //Downsampled with normals
  FILE* archivo;
  char buffer[40], *token;
  // cloud.reset(new  pcl::PointCloud<pcl::PointXYZ>);
  cloud->resize(3969);
  archivo = fopen("/home/catolica/Documents/Github/PCL-visualizer/viewer/src/downsamp_cloud.csv", "r+"); 
  for (auto& point: *cloud){
    fgets(buffer,sizeof(buffer),archivo);
    token = strtok(buffer," ");
    point.x=atof(token);
    token = strtok(NULL," ");
    point.y=atof(token);
    token = strtok(NULL," \n");
    point.z=atof(token);
  }

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

  // // Connect "random" button and the function
  // connect (ui->pushButton_random,  SIGNAL (clicked ()), this, SLOT (randomButtonPressed ()));

  // // Connect R,G,B sliders and their functions
  // connect (ui->horizontalSlider_R, SIGNAL (valueChanged (int)), this, SLOT (redSliderValueChanged (int)));
  // connect (ui->horizontalSlider_G, SIGNAL (valueChanged (int)), this, SLOT (greenSliderValueChanged (int)));
  // connect (ui->horizontalSlider_B, SIGNAL (valueChanged (int)), this, SLOT (blueSliderValueChanged (int)));
  // connect (ui->horizontalSlider_R, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));
  // connect (ui->horizontalSlider_G, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));
  // connect (ui->horizontalSlider_B, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));

  // Connect point size slider
  // connect (ui->horizontalSlider_p, SIGNAL (valueChanged (int)), this, SLOT (pSliderValueChanged (int)));

  // Normal estimation*
  pcl::NormalEstimation<PointT, pcl::Normal> n;
  pcl::PointCloud<pcl::Normal>::Ptr normals (new pcl::PointCloud<pcl::Normal>);
  pcl::search::KdTree<PointT>::Ptr tree (new pcl::search::KdTree<PointT>);
  tree->setInputCloud (cloud);
  n.setInputCloud (cloud);
  n.setSearchMethod (tree);
  n.setKSearch (20);
  n.compute (*normals);
  //* normals should not contain the point normals + surface curvatures

  // Concatenate the XYZ and normal fields*
  pcl::PointCloud<pcl::PointNormal>::Ptr cloud_with_normals (new pcl::PointCloud<pcl::PointNormal>);
  pcl::concatenateFields (*cloud, *normals, *cloud_with_normals);
  //* cloud_with_normals = cloud + normals

  // Create search tree*
  pcl::search::KdTree<pcl::PointNormal>::Ptr tree2 (new pcl::search::KdTree<pcl::PointNormal>);
  tree2->setInputCloud (cloud_with_normals);

  // // Initialize objects
  // pcl::GreedyProjectionTriangulation<pcl::PointNormal> gp3;
  pcl::PolygonMesh triangles;

  // // Set the maximum distance between connected points (maximum edge length)
  // gp3.setSearchRadius (100);

  // // Set typical values for the parameters
  // gp3.setMu (3);
  // gp3.setMaximumNearestNeighbors (100);
  // gp3.setMaximumSurfaceAngle(M_PI/4); // 45 degrees
  // gp3.setMinimumAngle(M_PI/18); // 10 degrees
  // gp3.setMaximumAngle(2*M_PI/3); // 120 degrees
  // gp3.setNormalConsistency(false);

  // // Get result
  // gp3.setInputCloud (cloud_with_normals);
  // gp3.setSearchMethod (tree2);
  // gp3.reconstruct (triangles);

  // // Additional vertex information
  // std::vector<int> parts = gp3.getPartIDs();
  // std::vector<int> states = gp3.getPointStates();

  pcl::Vertices vex;
  triangles.polygons.resize(7898);
  pcl::toPCLPointCloud2(*cloud, triangles.cloud);
  vex.vertices.resize(3);
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
    triangles.polygons[i]= vex;
  }

  // viewer->addPointCloud (cloud, "cloud");
  viewer -> addPolygonMesh (triangles, "mesh", 0);
  // pSliderValueChanged (2);
  viewer->resetCamera ();
  
  refreshView();
}

// void
// PCLViewer::randomButtonPressed ()
// {
//   printf ("Random button was pressed\n");

//   // Set the new color
//   for (auto& point: *cloud)
//   {
//     point.r = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
//     point.g = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
//     point.b = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
//   }

//   viewer->updatePointCloud (cloud, "cloud");
//   refreshView();
// }

// void
// PCLViewer::RGBsliderReleased ()
// {
//   // Set the new color
//   for (auto& point: *cloud)
//   {
//     point.r = red;
//     point.g = green;
//     point.b = blue;
//   }
//   viewer->updatePointCloud (cloud, "cloud");
//   refreshView();
// }

// void
// PCLViewer::pSliderValueChanged (int value)
// {
//   viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, value, "cloud");
//   refreshView();
// }

void
PCLViewer::refreshView()
{
#if VTK_MAJOR_VERSION > 8
  ui->qvtkWidget->renderWindow()->Render();
#else
  ui->qvtkWidget->update();
#endif
}

// void
// PCLViewer::redSliderValueChanged (int value)
// {
//   red = value;
//   printf ("redSliderValueChanged: [%d|%d|%d]\n", red, green, blue);
// }

// void
// PCLViewer::greenSliderValueChanged (int value)
// {
//   green = value;
//   printf ("greenSliderValueChanged: [%d|%d|%d]\n", red, green, blue);
// }

// void
// PCLViewer::blueSliderValueChanged (int value)
// {
//   blue = value;
//   printf("blueSliderValueChanged: [%d|%d|%d]\n", red, green, blue);
// }

PCLViewer::~PCLViewer ()
{
  delete ui;
}
