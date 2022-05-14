#include "Graph.h"
#define PI 3.141592653589793


Graph::Graph(QWidget* parent)
{
	lbl = new QLabel(this);
	QVBoxLayout* mainLayout = new QVBoxLayout();
	panel = new drawPanel(this);
	mainLayout->addWidget(panel);
	setLayout(mainLayout);
}

void Graph::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		scribbling = true;
		lbl->show();
	}
}

void Graph::mouseMoveEvent(QMouseEvent* event)
{
	if ((event->buttons() & Qt::LeftButton) && scribbling)
	{
		QPointF point = event->pos();
		lbl->setText(QString::number(((point.rx() - 450) + -(sin((point.rx() - 450) * (PI / 180)))) / 26));
		lbl->setGeometry(point.rx() + 10, point.ry() + 10, 50, 50);
	}
}

void Graph::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton && scribbling)
	{
		scribbling == false;
		lbl->hide();
	}
}

