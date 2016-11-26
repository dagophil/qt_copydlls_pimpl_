#ifndef MY_CUSTOM_WIDGET_H
#define MY_CUSTOM_WIDGET_H

#include <QWidget>

class MyCustomWidget : public QWidget
{
	Q_OBJECT
public:

	MyCustomWidget(QWidget* parent = nullptr);

signals:

	void foo_signal();

};

#endif
