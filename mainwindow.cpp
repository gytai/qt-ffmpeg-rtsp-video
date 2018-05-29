#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QDesktopWidget>
#include <QtCore/QCommandLineParser>
#include <QtCore/QCommandLineOption>
#include <QtCore/QDir>

#include <QThread>
#include <QPainter>
#include <QInputDialog>
#include <QtMath>

#include <QMouseEvent>
#include <QSettings>

#include<iostream>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    setWindowFlags(Qt::FramelessWindowHint);

    mPlayer = new VideoPlayer;
    connect(mPlayer,SIGNAL(sig_GetOneFrame(QImage)),this,SLOT(slotGetOneFrame(QImage)));

    connect(ui->Open_red,&QAction::triggered,this,&MainWindow::slotOpenRed);
    connect(ui->Close_Red,&QAction::triggered,this,&MainWindow::slotCloseRed);

    mPlayer->startPlay();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    //painter.setBrush(QColor(0,0,0,0));
    painter.setBrush(Qt::black);
    painter.drawRect(0, 0, this->width(), this->height()); //先画成白色

    if (mImage.size().width() <= 0) return;

    //将图像按比例缩放成和窗口一样大小
    QImage img = mImage.scaled(this->size(),Qt::KeepAspectRatioByExpanding);

    int x = this->width() - img.width();
    int y = this->height() - img.height();

    x /= 2;
    y /= 2;

    painter.drawImage(QPoint(x,y),img); //画出图像

}

void MainWindow::slotGetOneFrame(QImage img)
{
    mImage = img;
    update(); //调用update将执行 paintEvent函数
}

//小窗口显示
void MainWindow::slotGetRFrame(QImage img)
{
    R_mImage = img;
    update(); //调用update将执行 paintEvent函数
}
//显示图像红色通道,2017.8.12---lizhen
bool MainWindow::slotOpenRed()
{
    open_red=true;
    return open_red;
}
//关闭图像红色通道，2017.8.12
bool MainWindow::slotCloseRed()
{
    open_red=false;
    return open_red;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    qDebug() << "QKeyEvent:" <<key;
    if(key == Qt::Key_A){
        vWindow = new videowindow;
        vWindow->setAttribute(Qt::WA_DeleteOnClose,true);
        vWindow->showFullScreen();
    }

}

