#include "logger.h"
#include <logger/cout_logger.h>

CoutLogger& getCoutLogger()
{
  static CoutLogger instance;
  return instance;
}

std::ostream& operator<<(std::ostream& stream, EndLog const&)
{
  stream << "\n";
  stream.flush();
}

std::ostream loginfo(&getCoutLogger());
EndLog endlog;
