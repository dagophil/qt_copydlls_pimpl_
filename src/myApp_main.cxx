#include "myMainWindow.h"
#include <logger/logger.h>
#include <QApplication>


int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
  loginfo << "start" << endlog;
	MyMainWindow window;
	window.show();
  QObject::connect(&window, &MyMainWindow::closed,
    qApp, &QApplication::quit);
	return a.exec();
}
