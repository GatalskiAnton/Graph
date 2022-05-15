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
		lbl->setText(QString::number(((point.rx() - 450) / 32) * (point.rx() - 450) / 32 + sin((((point.rx() - 450) / 32)) * (PI / 90))));
		lbl->setGeometry(point.rx() + (width() + height()) / 180, point.ry() + (width() + height()) / 180, (width() + height()) / 36, (width() + height()) / 36);
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
void Graph::onClickedCalculateButton()
{
	editY->setText(QString::number(editX->text().toDouble() * editX->text().toDouble()) + (sin(editX->text().toDouble() * (PI / 180))));
}

