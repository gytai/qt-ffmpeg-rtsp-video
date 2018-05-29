#ifndef VIDEOWINDOW_H
#define VIDEOWINDOW_H

#include <QWidget>
#include "localvideoplayer.h"
#include "localvideoplayer.h"
#include <QtDebug>

namespace Ui {
class videowindow;
}

class videowindow : public QWidget
{
    Q_OBJECT

public:
    explicit videowindow(QWidget *parent = 0);
    ~videowindow();
    bool isClose = false;

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::videowindow *ui;

    LocalVideoPlayer *mLocalPlayer;

    QImage mImage;
    QImage R_mImage;

    QString url;
    QString videoPath;

    void keyPressEvent(QKeyEvent *event);

private slots:
    void slotGetVideoFrame(QImage img);
    void slotVideoFinished();
};

#endif // VIDEOWINDOW_H
