#pragma once
#include <QWidget>
#include <QPainter>

class drawPanel : public QWidget
{
	Q_OBJECT
public:
	explicit drawPanel(QWidget* parent = nullptr) {};
protected:
	void paintEvent(QPaintEvent* );
private:
	
};

