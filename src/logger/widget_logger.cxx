#include "widget_logger.h"

#include <QApplication>
#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QWidget>

#include <iostream>
#include <sstream>


class WidgetLogger::Pimpl
{
public:

  Pimpl();

  template <typename T>
  Pimpl& operator<<(T&& t);

  void flush();

private:

  void create_widget();

  QWidget* widget;
  QTextEdit* textEdit;
  std::stringstream ss;

};


WidgetLogger::WidgetLogger()
  :
  pimpl(new Pimpl())
{
}


WidgetLogger::~WidgetLogger()
{
  auto remain = str();
  if (remain.size() > 0)
  {
    (*this->pimpl) << remain;
    this->pimpl->flush();
  }
}


int WidgetLogger::sync()
{
  (*this->pimpl) << str();
  this->pimpl->flush();
  str("");
  return std::stringbuf::sync();
}


WidgetLogger::Pimpl::Pimpl()
  :
  widget(nullptr),
  textEdit(nullptr)
{
}


template <typename T>
WidgetLogger::Pimpl& WidgetLogger::Pimpl::operator<<(T&& t)
{
  ss << std::forward<T>(t);
  return *this;
}


void WidgetLogger::Pimpl::flush()
{
  if (!widget)
    this->create_widget();
  this->textEdit->setText(this->textEdit->toPlainText() + QString::fromStdString(ss.str()));
  ss.str("");
}


void WidgetLogger::Pimpl::create_widget()
{
  this->widget = new QWidget();
  this->widget->setFixedSize(800, 600);
  this->widget->setContentsMargins(0, 0, 0, 0);
  this->widget->setAttribute(Qt::WA_DeleteOnClose);
  QObject::connect(this->widget, &QWidget::destroyed,
    qApp, &QApplication::quit);

  this->textEdit = new QTextEdit();
  this->textEdit->setReadOnly(true);
  this->textEdit->setContentsMargins(0, 0, 0, 0);
  this->textEdit->setFontFamily("Courier New");

  auto palette = this->textEdit->palette();
  palette.setColor(QPalette::Base, QColor(0, 0, 0));
  palette.setColor(QPalette::Text, QColor(255, 255, 255));

  this->textEdit->setPalette(palette);

  auto layout = new QVBoxLayout(this->widget);
  layout->setContentsMargins(0, 0, 0, 0);
  layout->addWidget(this->textEdit);

  this->widget->show();
}
