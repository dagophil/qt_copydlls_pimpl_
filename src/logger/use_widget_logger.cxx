#include "logger.h"
#include <logger/widget_logger.h>

WidgetLogger& getWidgetLogger()
{
  static WidgetLogger instance;
  return instance;
}

std::ostream& operator<<(std::ostream& stream, EndLog const&)
{
  stream << "\n";
  stream.flush();
}

std::ostream loginfo(&getWidgetLogger());
EndLog endlog;
