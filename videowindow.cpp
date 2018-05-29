#include "videowindow.h"
#include "ui_videowindow.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QDesktopWidget>
#include <QtCore/QCommandLineParser>
#include <QtCore/QCommandLineOption>
#include <QtCore/QDir>

#include <QThread>
#include <QPainter>
#include <QInputDialog>
#include <QtMath>

#include <QSettings>
#include <QString>
#include <QDebug>

#include <QMouseEvent>

videowindow::videowindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::videowindow)
{
   ui->setupUi(this);

   setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
   setAttribute(Qt::WA_TranslucentBackground);
   setFocusPolicy(Qt::StrongFocus);

   QSettings *configIniRead = new QSettings("config.ini", QSettings::IniFormat);
   //将读取到的ini文件保存在QString中，先取值，然后通过toString()函数转换成QString类型

   QString videoPath = configIniRead->value("/video/path").toString();
   //读入入完成后删除指针
   delete configIniRead;

   mLocalPlayer = new LocalVideoPlayer(videoPath);
   connect(mLocalPlayer,SIGNAL(sig_GetVideoFrame(QImage)),this,SLOT(slotGetVideoFrame(QImage)));
   connect(mLocalPlayer,SIGNAL(sig_VideoFinished()),this,SLOT(slotVideoFinished()));

   mLocalPlayer->startPlay();
}

videowindow::~videowindow()
{
    delete ui;
}

void videowindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(QColor(0,0,0,0));
    //painter.setBrush(Qt::black);
    //painter.drawRect(0, 0, this->width(), this->height()); //先画成白色

    if (mImage.size().width() <= 0) return;

    //将图像按比例缩放成和窗口一样大小
    QImage img = mImage.scaled(this->size(),Qt::KeepAspectRatioByExpanding);

    int x = this->width() - img.width();
    int y = this->height() - img.height();

    x /= 2;
    y /= 2;

    painter.drawImage(QPoint(x,y),img); //画出图像
}

void videowindow::slotGetVideoFrame(QImage img)
{
    mImage = img;
    update(); //调用update将执行 paintEvent函数
}

void videowindow::slotVideoFinished()
{
     qDebug() << "slotVideoFinished!!";

     isClose = true;
     this->setWindowFlags(Qt::SubWindow);
     this->showNormal();
     this->close();
}

void videowindow::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    qDebug() << "videowindow QKeyEvent" <<key;

    isClose = true;
    this->setWindowFlags(Qt::SubWindow);
    this->showNormal();
    this->close();
}
