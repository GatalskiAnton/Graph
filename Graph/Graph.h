#pragma once

#include <QtWidgets/QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMouseEvent>
#include <QLineEdit>
#include "drawPanel.h"

class Graph : public QWidget
{
    Q_OBJECT

public:
    Graph(QWidget *parent = Q_NULLPTR);
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
protected:
    void paintEvent(QPaintEvent*);
protected slots:
    void onClickedCalculateButton();
private:
    bool scribbling ;
    QLabel* lbl;
    QLineEdit* editX;
    QLineEdit* editY;
    drawPanel* panel;
    QPainter* painter;
    double x = 10;
    double y = 10;
    void point(double x = 10, double y = 10);
};
