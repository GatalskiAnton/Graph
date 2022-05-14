/********************************************************************************
** Form generated from reading UI file 'Graph.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPH_H
#define UI_GRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GraphClass)
    {
        if (GraphClass->objectName().isEmpty())
            GraphClass->setObjectName(QString::fromUtf8("GraphClass"));
        GraphClass->resize(600, 400);
        menuBar = new QMenuBar(GraphClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        GraphClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GraphClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GraphClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(GraphClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        GraphClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GraphClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GraphClass->setStatusBar(statusBar);

        retranslateUi(GraphClass);

        QMetaObject::connectSlotsByName(GraphClass);
    } // setupUi

    void retranslateUi(QMainWindow *GraphClass)
    {
        GraphClass->setWindowTitle(QCoreApplication::translate("GraphClass", "Graph", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GraphClass: public Ui_GraphClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPH_H
