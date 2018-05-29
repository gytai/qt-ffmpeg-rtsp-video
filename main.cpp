#include "mainwindow.h"


#include <QApplication>

#include <QTextCodec>

#include "localvideoplayer.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QDesktopWidget>
#include <QtCore/QCommandLineParser>
#include <QtCore/QCommandLineOption>
#include <QtCore/QDir>

#include <QGraphicsScene>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QTextCodec *codec = QTextCodec::codecForName("UTF-8"); //设置编码格式为UTF-8
    QTextCodec::setCodecForLocale(codec);

    MainWindow w;
    w.showFullScreen();


    return app.exec();
}
