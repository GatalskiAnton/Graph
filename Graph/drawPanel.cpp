#include "drawPanel.h"
#define PI 3.141592653589793

void drawPanel::paintEvent(QPaintEvent* event)
{
	painter = new QPainter(this);
	int midX = width() / 2;
	int midY = height() / 2;
	int margin = 20;
	painter->setPen(QPen(Qt::black, 3));
	QPoint origin = QPoint(midX, midY);
	painter->translate(origin);
	painter->drawLine(-width(), 0, width() , 0);
	painter->drawLine(0, height(), 0, -height());

	double dx = (width() - margin) / 26;
	double dy = (height() - margin) / 26;

	painter->setFont(QFont("arial", (width() + height()) / 200));
	for (int i = -26 / 2 + 2; i <= 26 / 2 - 2; i++)
	{
		painter->drawLine(i * dx,dy / 7 , i * dx, -dy / 7);
		painter->drawLine(dy / 7, i * dx, -dy / 7, i * dx);
		if (i == 0) continue;
		painter->drawText(i * dx, dy / 7 + dy, QString::number(i));
		painter->drawText( - (dy / 7 + dy), i * dx, QString::number(-i));
	}
	painter->drawLine(width() / 2 - 2 * dx, -dy, width() / 2 , 0);
	painter->drawLine(width() / 2 - 2 * dx, dy, width() / 2, 0);

	painter->drawLine(dy,  -(height() / 2 - 2 * dx), 0, -(height() / 2));
	painter->drawLine(-dy, -(height() / 2 - 2 * dx), 0, -(height() / 2));

	painter->setPen(QPen(Qt::red, 7));
	painter->drawPoint(0, 0);
	painter->setPen(QPen(QColor(7,94,223), 3));

	for (double i = -13*dx; i < 13* dx; i+=dx*0.01)
	{
		QPointF point;
		point.rx() = i;
		point.ry() = -point.rx() * point.rx() / dy -(sin(point.rx() * (PI / 90))) *dy;
		painter->drawPoint(point);
	}
}
