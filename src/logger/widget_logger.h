#ifndef WIDGET_LOGGER_H
#define WIDGET_LOGGER_H

#include <memory>
#include <sstream>

class WidgetLogger : public std::stringbuf
{
public:

  WidgetLogger();
  virtual ~WidgetLogger();

protected:

  virtual int sync() override;

private:

  class Pimpl;
  std::unique_ptr<Pimpl> pimpl;

};

#endif
