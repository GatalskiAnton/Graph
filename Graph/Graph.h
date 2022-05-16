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

protected slots:
    void onClickedCalculateButton();
private:
    QLabel* lbl;
    QLineEdit* editX;
    QLineEdit* editY;
    drawPanel* panel;
};
