/********************************************************************************
** Form generated from reading UI file 'videowindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOWINDOW_H
#define UI_VIDEOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_videowindow
{
public:

    void setupUi(QWidget *videowindow)
    {
        if (videowindow->objectName().isEmpty())
            videowindow->setObjectName(QStringLiteral("videowindow"));
        videowindow->resize(400, 300);

        retranslateUi(videowindow);

        QMetaObject::connectSlotsByName(videowindow);
    } // setupUi

    void retranslateUi(QWidget *videowindow)
    {
        videowindow->setWindowTitle(QApplication::translate("videowindow", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class videowindow: public Ui_videowindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOWINDOW_H
