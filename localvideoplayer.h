#ifndef LOCALVIDEOPLAYER_H
#define LOCALVIDEOPLAYER_H

#include <QThread>
#include <QImage>

class VlcInstance;
class VlcMedia;
class VlcMediaPlayer;

class LocalVideoPlayer : public QThread
{
    Q_OBJECT

public:
    explicit LocalVideoPlayer(QString path);
    ~LocalVideoPlayer();

    void startPlay();

signals:
    void sig_GetVideoFrame(QImage); //每获取到一帧图像 就发送此信号
    void sig_VideoFinished();

protected:
    void run();

private:
    QString mFileName;

    //2017.8.10---lizhen
    VlcInstance *_instance;
    VlcMedia *_media;
    VlcMediaPlayer *_player;
};

#endif // LOCALVIDEOPLAYER_H
