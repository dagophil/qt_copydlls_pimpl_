#ifndef MY_MAIN_WINDOW_H
#define MY_MAIN_WINDOW_H

#include <QMainWindow>


class MyMainWindow : public QMainWindow
{
	Q_OBJECT
public:

	MyMainWindow();

signals:

  void closed();

public slots:

	void foo();

protected:

  virtual void closeEvent(QCloseEvent* event) override;

private:

	bool console_visible;

};

#endif
