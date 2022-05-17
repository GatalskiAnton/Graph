#pragma once
#include <QWidget>
#include <QPainter>

class drawPanel : public QWidget
{
	Q_OBJECT
public:
	explicit drawPanel(QWidget* parent = nullptr) {};
	double getDx();
	double getDy();
	void point(double x = 0.0, double y = 0.0);
protected:
	void paintEvent(QPaintEvent* );
private:
	double dx;
	double dy;
	QPainter* painter;
};
double func(double x);
