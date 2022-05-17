#include "Graph.h"
#define PI 3.141592653589793


Graph::Graph(QWidget* parent)
{
	lbl = new QLabel(this);
	editX = new QLineEdit(this);
	editY = new QLineEdit(this);
	editY->setReadOnly(true);
	QPushButton* calculateButton = new QPushButton("F(X)", this);
	QVBoxLayout* mainLayout = new QVBoxLayout();
	panel = new drawPanel(this);
	mainLayout->addWidget(panel);
	mainLayout->addWidget(editX);
	mainLayout->addWidget(calculateButton);
	mainLayout->addWidget(editY);
	connect(calculateButton, SIGNAL(clicked()), SLOT(onClickedCalculateButton()));
	setLayout(mainLayout);
}

void Graph::paintEvent(QPaintEvent* event) 
{
	painter = new QPainter(this);
	painter->setPen(QPen(Qt::black, 8));
	if (scribbling == true)
	{
		point(x,y);
	}
	
}

void Graph::point(double x, double y)
{
	painter->drawPoint(x, y);
}

void Graph::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		lbl->show();
		scribbling = true;
	}
}

void Graph::mouseMoveEvent(QMouseEvent* event)
{
	if ((event->buttons() & Qt::LeftButton))
	{
		QPointF point = event->pos();
		double X = point.rx() - width() / 2;
		double dx = panel->getDx();
		lbl->setText(QString::number(func(X / 33)));
		lbl->setGeometry(point.rx() + (width() + height()) / 180, point.ry() + (width() + height()) / 180, (width() + height()) / 36, (width() + height()) / 36);
		x = event->pos().rx();
		y = func((event->pos().rx() - width() / 2) / 33);
		update();

	}
}

void Graph::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton )
	{
		lbl->hide();
		scribbling = false;
		update();

	}
}
void Graph::onClickedCalculateButton()
{
	editY->setText(QString::number(func(editX->text().toDouble())));
}

