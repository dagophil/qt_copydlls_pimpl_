#include "myMainWindow.h"
#include <myCustomWidget.h>
#include <logger/logger.h>
#include <QCloseEvent>

MyMainWindow::MyMainWindow()
	:
	console_visible(true)
{
	auto w = new MyCustomWidget(this);
	connect(w, &MyCustomWidget::foo_signal,
		this, &MyMainWindow::foo);
}

void MyMainWindow::foo()
{
  loginfo << "foo()" << endlog;
}

void MyMainWindow::closeEvent(QCloseEvent* event)
{
  event->accept();
  emit this->closed();
}
