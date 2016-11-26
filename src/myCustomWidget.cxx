#include "myCustomWidget.h"
#include <QPushButton>

MyCustomWidget::MyCustomWidget(QWidget* parent)
	:
	QWidget(parent)
{
	auto button = new QPushButton("Press me", this);
	connect(button, &QPushButton::clicked,
		this, &MyCustomWidget::foo_signal);
}
