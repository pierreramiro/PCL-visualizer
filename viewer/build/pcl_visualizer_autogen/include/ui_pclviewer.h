/********************************************************************************
** Form generated from reading UI file 'pclviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCLVIEWER_H
#define UI_PCLVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include <pcl/visualization/qvtk_compatibility.h>

QT_BEGIN_NAMESPACE

class Ui_PCLViewer
{
public:
    QAction *action_csv;
    QAction *action_ply;
    QAction *action_pcd;
    QAction *action;
    QAction *action_dxf;
    QAction *action_obj;
    QAction *action_las;
    QWidget *centralwidget;
    PCLQVTKWidget *qvtkWidget;
    QPushButton *pushButton_PointCloud;
    QPushButton *pushButton_Surface;
    QLabel *label_Density;
    QLabel *label_Type;
    QComboBox *comboBox_Density;
    QLabel *label_PointSize;
    QSlider *horizontalSlider_PointSize;
    QLCDNumber *lcdnumber_PointSize;
    QTableWidget *tableWidget;
    QPushButton *pushButton_yellow;
    QPushButton *pushButton_black;
    QPushButton *pushButton_white;
    QPushButton *pushButton_red;
    QPushButton *pushButton_blue;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuExport;
    QMenu *menuPoint_Cloud;
    QMenu *menuSurface;

    void setupUi(QMainWindow *PCLViewer)
    {
        if (PCLViewer->objectName().isEmpty())
            PCLViewer->setObjectName(QStringLiteral("PCLViewer"));
        PCLViewer->resize(1198, 743);
        PCLViewer->setMinimumSize(QSize(0, 0));
        PCLViewer->setMaximumSize(QSize(5000, 5000));
        action_csv = new QAction(PCLViewer);
        action_csv->setObjectName(QStringLiteral("action_csv"));
        action_ply = new QAction(PCLViewer);
        action_ply->setObjectName(QStringLiteral("action_ply"));
        action_pcd = new QAction(PCLViewer);
        action_pcd->setObjectName(QStringLiteral("action_pcd"));
        action = new QAction(PCLViewer);
        action->setObjectName(QStringLiteral("action"));
        action_dxf = new QAction(PCLViewer);
        action_dxf->setObjectName(QStringLiteral("action_dxf"));
        action_obj = new QAction(PCLViewer);
        action_obj->setObjectName(QStringLiteral("action_obj"));
        action_las = new QAction(PCLViewer);
        action_las->setObjectName(QStringLiteral("action_las"));
        centralwidget = new QWidget(PCLViewer);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        qvtkWidget = new PCLQVTKWidget(centralwidget);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));
        qvtkWidget->setGeometry(QRect(380, 20, 801, 681));
        pushButton_PointCloud = new QPushButton(centralwidget);
        pushButton_PointCloud->setObjectName(QStringLiteral("pushButton_PointCloud"));
        pushButton_PointCloud->setGeometry(QRect(30, 60, 121, 61));
        pushButton_Surface = new QPushButton(centralwidget);
        pushButton_Surface->setObjectName(QStringLiteral("pushButton_Surface"));
        pushButton_Surface->setGeometry(QRect(190, 60, 121, 61));
        label_Density = new QLabel(centralwidget);
        label_Density->setObjectName(QStringLiteral("label_Density"));
        label_Density->setGeometry(QRect(30, 140, 67, 17));
        label_Type = new QLabel(centralwidget);
        label_Type->setObjectName(QStringLiteral("label_Type"));
        label_Type->setGeometry(QRect(30, 30, 67, 17));
        comboBox_Density = new QComboBox(centralwidget);
        comboBox_Density->setObjectName(QStringLiteral("comboBox_Density"));
        comboBox_Density->setGeometry(QRect(30, 170, 141, 25));
        label_PointSize = new QLabel(centralwidget);
        label_PointSize->setObjectName(QStringLiteral("label_PointSize"));
        label_PointSize->setGeometry(QRect(30, 220, 67, 17));
        horizontalSlider_PointSize = new QSlider(centralwidget);
        horizontalSlider_PointSize->setObjectName(QStringLiteral("horizontalSlider_PointSize"));
        horizontalSlider_PointSize->setGeometry(QRect(30, 250, 211, 41));
        horizontalSlider_PointSize->setMinimum(1);
        horizontalSlider_PointSize->setMaximum(5);
        horizontalSlider_PointSize->setValue(2);
        horizontalSlider_PointSize->setSliderPosition(2);
        horizontalSlider_PointSize->setTracking(true);
        horizontalSlider_PointSize->setOrientation(Qt::Horizontal);
        horizontalSlider_PointSize->setInvertedControls(false);
        horizontalSlider_PointSize->setTickPosition(QSlider::NoTicks);
        lcdnumber_PointSize = new QLCDNumber(centralwidget);
        lcdnumber_PointSize->setObjectName(QStringLiteral("lcdnumber_PointSize"));
        lcdnumber_PointSize->setGeometry(QRect(260, 240, 51, 51));
        lcdnumber_PointSize->setMouseTracking(false);
        lcdnumber_PointSize->setTabletTracking(false);
        lcdnumber_PointSize->setFrameShape(QFrame::StyledPanel);
        lcdnumber_PointSize->setSmallDecimalPoint(false);
        lcdnumber_PointSize->setDigitCount(1);
        lcdnumber_PointSize->setSegmentStyle(QLCDNumber::Flat);
        lcdnumber_PointSize->setProperty("value", QVariant(2));
        lcdnumber_PointSize->setProperty("intValue", QVariant(2));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tableWidget->rowCount() < 3)
            tableWidget->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(50, 460, 251, 121));
        pushButton_yellow = new QPushButton(centralwidget);
        pushButton_yellow->setObjectName(QStringLiteral("pushButton_yellow"));
        pushButton_yellow->setGeometry(QRect(330, 30, 41, 41));
        pushButton_yellow->setStyleSheet(QStringLiteral("background-color:rgb(237, 212, 0)"));
        pushButton_black = new QPushButton(centralwidget);
        pushButton_black->setObjectName(QStringLiteral("pushButton_black"));
        pushButton_black->setGeometry(QRect(330, 80, 41, 41));
        pushButton_black->setStyleSheet(QStringLiteral("background-color:rgb(0, 0, 0)"));
        pushButton_white = new QPushButton(centralwidget);
        pushButton_white->setObjectName(QStringLiteral("pushButton_white"));
        pushButton_white->setGeometry(QRect(330, 130, 41, 41));
        pushButton_white->setStyleSheet(QLatin1String("background-color:rgb(255,255,255\n"
")"));
        pushButton_red = new QPushButton(centralwidget);
        pushButton_red->setObjectName(QStringLiteral("pushButton_red"));
        pushButton_red->setGeometry(QRect(330, 180, 41, 41));
        pushButton_red->setStyleSheet(QStringLiteral("background-color:rgb(239, 41, 41)"));
        pushButton_blue = new QPushButton(centralwidget);
        pushButton_blue->setObjectName(QStringLiteral("pushButton_blue"));
        pushButton_blue->setGeometry(QRect(330, 230, 41, 41));
        pushButton_blue->setStyleSheet(QStringLiteral("background-color:rgb(52, 101, 164)"));
        PCLViewer->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(PCLViewer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1198, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuExport = new QMenu(menuFile);
        menuExport->setObjectName(QStringLiteral("menuExport"));
        menuPoint_Cloud = new QMenu(menuExport);
        menuPoint_Cloud->setObjectName(QStringLiteral("menuPoint_Cloud"));
        menuSurface = new QMenu(menuExport);
        menuSurface->setObjectName(QStringLiteral("menuSurface"));
        PCLViewer->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(menuExport->menuAction());
        menuExport->addAction(menuPoint_Cloud->menuAction());
        menuExport->addSeparator();
        menuExport->addAction(menuSurface->menuAction());
        menuPoint_Cloud->addAction(action_ply);
        menuPoint_Cloud->addAction(action_pcd);
        menuPoint_Cloud->addAction(action_csv);
        menuPoint_Cloud->addAction(action);
        menuPoint_Cloud->addAction(action_las);
        menuSurface->addAction(action_dxf);
        menuSurface->addAction(action_obj);
        menuSurface->addAction(action_ply);

        retranslateUi(PCLViewer);

        QMetaObject::connectSlotsByName(PCLViewer);
    } // setupUi

    void retranslateUi(QMainWindow *PCLViewer)
    {
        PCLViewer->setWindowTitle(QApplication::translate("PCLViewer", "PCLViewer", Q_NULLPTR));
        action_csv->setText(QApplication::translate("PCLViewer", ".csv", Q_NULLPTR));
        action_ply->setText(QApplication::translate("PCLViewer", ".ply", Q_NULLPTR));
        action_pcd->setText(QApplication::translate("PCLViewer", ".pcd", Q_NULLPTR));
        action->setText(QApplication::translate("PCLViewer", ".bin", Q_NULLPTR));
        action_dxf->setText(QApplication::translate("PCLViewer", ".dxf", Q_NULLPTR));
        action_obj->setText(QApplication::translate("PCLViewer", ".obj", Q_NULLPTR));
        action_las->setText(QApplication::translate("PCLViewer", ".las", Q_NULLPTR));
        pushButton_PointCloud->setText(QApplication::translate("PCLViewer", "Point \n"
"Cloud", Q_NULLPTR));
        pushButton_Surface->setText(QApplication::translate("PCLViewer", "Surface \n"
"Reconstruction", Q_NULLPTR));
        label_Density->setText(QApplication::translate("PCLViewer", "Density", Q_NULLPTR));
        label_Type->setText(QApplication::translate("PCLViewer", "Type", Q_NULLPTR));
        comboBox_Density->clear();
        comboBox_Density->insertItems(0, QStringList()
         << QApplication::translate("PCLViewer", "Minimum (1/8)", Q_NULLPTR)
         << QApplication::translate("PCLViewer", "Medium (1/4)", Q_NULLPTR)
         << QApplication::translate("PCLViewer", "Maximum (1/1)", Q_NULLPTR)
        );
        label_PointSize->setText(QApplication::translate("PCLViewer", "Point Size", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("PCLViewer", "Value", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("PCLViewer", "Number of points", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QApplication::translate("PCLViewer", "Number of triangles", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QApplication::translate("PCLViewer", "Box dimensions", Q_NULLPTR));
        pushButton_yellow->setText(QString());
        pushButton_black->setText(QString());
        pushButton_white->setText(QString());
        pushButton_red->setText(QString());
        pushButton_blue->setText(QString());
        menuFile->setTitle(QApplication::translate("PCLViewer", "File", Q_NULLPTR));
        menuExport->setTitle(QApplication::translate("PCLViewer", "Export", Q_NULLPTR));
        menuPoint_Cloud->setTitle(QApplication::translate("PCLViewer", "Point Cloud", Q_NULLPTR));
        menuSurface->setTitle(QApplication::translate("PCLViewer", "Surface", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PCLViewer: public Ui_PCLViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCLVIEWER_H
