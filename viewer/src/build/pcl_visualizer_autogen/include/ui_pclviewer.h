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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include <pcl/visualization/qvtk_compatibility.h>

QT_BEGIN_NAMESPACE

class Ui_PCLViewer
{
public:
    QWidget *centralwidget;
    PCLQVTKWidget *qvtkWidget;
    QSlider *horizontalSlider_R;
    QSlider *horizontalSlider_G;
    QSlider *horizontalSlider_B;
    QLCDNumber *lcdNumber_R;
    QLCDNumber *lcdNumber_G;
    QLCDNumber *lcdNumber_B;
    QSlider *horizontalSlider_p;
    QLCDNumber *lcdNumber_p;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_random;
    QPushButton *pushButton_add;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_blackbackground;
    QPushButton *pushButton_yellowbackground;
    QPushButton *pushButton_redbackground;
    QPushButton *pushButton_whitebackground;
    QPushButton *pushButton_bluebackground;

    void setupUi(QMainWindow *PCLViewer)
    {
        if (PCLViewer->objectName().isEmpty())
            PCLViewer->setObjectName(QStringLiteral("PCLViewer"));
        PCLViewer->resize(1018, 499);
        PCLViewer->setMinimumSize(QSize(0, 0));
        PCLViewer->setMaximumSize(QSize(5000, 5000));
        centralwidget = new QWidget(PCLViewer);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        qvtkWidget = new PCLQVTKWidget(centralwidget);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));
        qvtkWidget->setGeometry(QRect(300, 10, 640, 480));
        horizontalSlider_R = new QSlider(centralwidget);
        horizontalSlider_R->setObjectName(QStringLiteral("horizontalSlider_R"));
        horizontalSlider_R->setGeometry(QRect(30, 60, 160, 29));
        horizontalSlider_R->setMaximum(255);
        horizontalSlider_R->setValue(128);
        horizontalSlider_R->setOrientation(Qt::Horizontal);
        horizontalSlider_G = new QSlider(centralwidget);
        horizontalSlider_G->setObjectName(QStringLiteral("horizontalSlider_G"));
        horizontalSlider_G->setGeometry(QRect(30, 140, 160, 29));
        horizontalSlider_G->setMaximum(255);
        horizontalSlider_G->setValue(128);
        horizontalSlider_G->setOrientation(Qt::Horizontal);
        horizontalSlider_B = new QSlider(centralwidget);
        horizontalSlider_B->setObjectName(QStringLiteral("horizontalSlider_B"));
        horizontalSlider_B->setGeometry(QRect(30, 220, 160, 29));
        horizontalSlider_B->setMaximum(255);
        horizontalSlider_B->setValue(128);
        horizontalSlider_B->setOrientation(Qt::Horizontal);
        lcdNumber_R = new QLCDNumber(centralwidget);
        lcdNumber_R->setObjectName(QStringLiteral("lcdNumber_R"));
        lcdNumber_R->setGeometry(QRect(200, 50, 81, 41));
        lcdNumber_R->setDigitCount(3);
        lcdNumber_R->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_R->setProperty("intValue", QVariant(128));
        lcdNumber_G = new QLCDNumber(centralwidget);
        lcdNumber_G->setObjectName(QStringLiteral("lcdNumber_G"));
        lcdNumber_G->setGeometry(QRect(200, 130, 81, 41));
        lcdNumber_G->setDigitCount(3);
        lcdNumber_G->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_G->setProperty("intValue", QVariant(128));
        lcdNumber_B = new QLCDNumber(centralwidget);
        lcdNumber_B->setObjectName(QStringLiteral("lcdNumber_B"));
        lcdNumber_B->setGeometry(QRect(200, 210, 81, 41));
        lcdNumber_B->setDigitCount(3);
        lcdNumber_B->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_B->setProperty("intValue", QVariant(128));
        horizontalSlider_p = new QSlider(centralwidget);
        horizontalSlider_p->setObjectName(QStringLiteral("horizontalSlider_p"));
        horizontalSlider_p->setGeometry(QRect(30, 320, 160, 29));
        horizontalSlider_p->setMinimum(1);
        horizontalSlider_p->setMaximum(6);
        horizontalSlider_p->setValue(2);
        horizontalSlider_p->setOrientation(Qt::Horizontal);
        lcdNumber_p = new QLCDNumber(centralwidget);
        lcdNumber_p->setObjectName(QStringLiteral("lcdNumber_p"));
        lcdNumber_p->setGeometry(QRect(200, 310, 81, 41));
        lcdNumber_p->setDigitCount(1);
        lcdNumber_p->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_p->setProperty("intValue", QVariant(2));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 191, 31));
        QFont font;
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 100, 191, 31));
        label_2->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 190, 191, 31));
        label_3->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 280, 141, 31));
        label_4->setFont(font);
        pushButton_random = new QPushButton(centralwidget);
        pushButton_random->setObjectName(QStringLiteral("pushButton_random"));
        pushButton_random->setGeometry(QRect(80, 420, 141, 41));
        pushButton_add = new QPushButton(centralwidget);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));
        pushButton_add->setGeometry(QRect(40, 380, 101, 31));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_add->sizePolicy().hasHeightForWidth());
        pushButton_add->setSizePolicy(sizePolicy);
        pushButton_add->setMinimumSize(QSize(0, 0));
        pushButton_add->setMaximumSize(QSize(16777215, 16777215));
        pushButton_clear = new QPushButton(centralwidget);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));
        pushButton_clear->setGeometry(QRect(160, 380, 101, 31));
        pushButton_clear->setMinimumSize(QSize(0, 0));
        pushButton_clear->setMaximumSize(QSize(16777215, 16777215));
        pushButton_blackbackground = new QPushButton(centralwidget);
        pushButton_blackbackground->setObjectName(QStringLiteral("pushButton_blackbackground"));
        pushButton_blackbackground->setGeometry(QRect(960, 10, 41, 41));
        pushButton_blackbackground->setAutoFillBackground(false);
        pushButton_blackbackground->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0)"));
        pushButton_yellowbackground = new QPushButton(centralwidget);
        pushButton_yellowbackground->setObjectName(QStringLiteral("pushButton_yellowbackground"));
        pushButton_yellowbackground->setGeometry(QRect(960, 60, 41, 41));
        pushButton_yellowbackground->setAutoFillBackground(false);
        pushButton_yellowbackground->setStyleSheet(QStringLiteral("background-color: rgb(237, 212, 0)"));
        pushButton_redbackground = new QPushButton(centralwidget);
        pushButton_redbackground->setObjectName(QStringLiteral("pushButton_redbackground"));
        pushButton_redbackground->setGeometry(QRect(960, 110, 41, 41));
        pushButton_redbackground->setAutoFillBackground(false);
        pushButton_redbackground->setStyleSheet(QStringLiteral("background-color: rgb(204, 0, 0)"));
        pushButton_whitebackground = new QPushButton(centralwidget);
        pushButton_whitebackground->setObjectName(QStringLiteral("pushButton_whitebackground"));
        pushButton_whitebackground->setGeometry(QRect(960, 160, 41, 41));
        pushButton_whitebackground->setAutoFillBackground(false);
        pushButton_whitebackground->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255)"));
        pushButton_bluebackground = new QPushButton(centralwidget);
        pushButton_bluebackground->setObjectName(QStringLiteral("pushButton_bluebackground"));
        pushButton_bluebackground->setGeometry(QRect(960, 210, 41, 41));
        pushButton_bluebackground->setAutoFillBackground(false);
        pushButton_bluebackground->setStyleSheet(QStringLiteral("background-color:rgb(52, 101, 164)"));
        PCLViewer->setCentralWidget(centralwidget);

        retranslateUi(PCLViewer);
        QObject::connect(horizontalSlider_R, SIGNAL(sliderMoved(int)), lcdNumber_R, SLOT(display(int)));
        QObject::connect(horizontalSlider_G, SIGNAL(sliderMoved(int)), lcdNumber_G, SLOT(display(int)));
        QObject::connect(horizontalSlider_B, SIGNAL(sliderMoved(int)), lcdNumber_B, SLOT(display(int)));
        QObject::connect(horizontalSlider_p, SIGNAL(sliderMoved(int)), lcdNumber_p, SLOT(display(int)));

        QMetaObject::connectSlotsByName(PCLViewer);
    } // setupUi

    void retranslateUi(QMainWindow *PCLViewer)
    {
        PCLViewer->setWindowTitle(QApplication::translate("PCLViewer", "PCLViewer", Q_NULLPTR));
        label->setText(QApplication::translate("PCLViewer", "Red component", Q_NULLPTR));
        label_2->setText(QApplication::translate("PCLViewer", "Green component", Q_NULLPTR));
        label_3->setText(QApplication::translate("PCLViewer", "Blue component", Q_NULLPTR));
        label_4->setText(QApplication::translate("PCLViewer", "Point size", Q_NULLPTR));
        pushButton_random->setText(QApplication::translate("PCLViewer", "Random colors", Q_NULLPTR));
        pushButton_add->setText(QApplication::translate("PCLViewer", "AddDonut", Q_NULLPTR));
        pushButton_clear->setText(QApplication::translate("PCLViewer", "Clear", Q_NULLPTR));
        pushButton_blackbackground->setText(QString());
        pushButton_yellowbackground->setText(QString());
        pushButton_redbackground->setText(QString());
        pushButton_whitebackground->setText(QString());
        pushButton_bluebackground->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PCLViewer: public Ui_PCLViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCLVIEWER_H
