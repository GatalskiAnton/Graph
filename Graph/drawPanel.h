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
protected:
	void paintEvent(QPaintEvent* );
private:
	double dx;
	double dy;
	QPainter* painter;
};
double func(double x);
