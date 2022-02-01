#include "pclviewer.h"
#include <QApplication>
#include <QMainWindow>

int main (int argc, char *argv[])
{
  QApplication a (argc, argv);
  PCLViewer w;
  w.show ();

  return a.exec ();
}

/*

mesh.polygons.clear();
  pcl::toPCLPointCloud2(cloud, mesh.cloud);
  mesh.polygons.resize(91000);
  Vex.vertices.resize(3);
  Vex.vertices[i]
  mesh.polygons[]=Vex; */