/********************************************************************************
** Form generated from reading UI file 'geolab.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GEOLAB_H
#define UI_GEOLAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GeolabClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GeolabClass)
    {
        if (GeolabClass->objectName().isEmpty())
            GeolabClass->setObjectName(QStringLiteral("GeolabClass"));
        GeolabClass->resize(600, 400);
        menuBar = new QMenuBar(GeolabClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        GeolabClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GeolabClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GeolabClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(GeolabClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        GeolabClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GeolabClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GeolabClass->setStatusBar(statusBar);

        retranslateUi(GeolabClass);

        QMetaObject::connectSlotsByName(GeolabClass);
    } // setupUi

    void retranslateUi(QMainWindow *GeolabClass)
    {
        GeolabClass->setWindowTitle(QApplication::translate("GeolabClass", "Geolab", 0));
    } // retranslateUi

};

namespace Ui {
    class GeolabClass: public Ui_GeolabClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GEOLAB_H
