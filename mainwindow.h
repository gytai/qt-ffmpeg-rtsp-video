#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QImage>
#include <QPaintEvent>
#include <QWidget>
#include <QtDebug>

#include <QtConcurrent/qtconcurrentrun.h>
#include "videoplayer.h"
#include "localvideoplayer.h"
#include "videowindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::MainWindow *ui;
    VideoPlayer *mPlayer;
    LocalVideoPlayer *mLocalPlayer;

    QImage mImage;
    QImage R_mImage;

    QString url;

    videowindow *vWindow;

    bool open_red=false;
    void keyPressEvent(QKeyEvent *event);

    QString rtspUrl;
    QString videoPath;

private slots:
    void slotGetOneFrame(QImage img);
    void slotGetRFrame(QImage img);
    bool slotOpenRed();
    bool slotCloseRed();
};

#endif // MAINWINDOW_H
