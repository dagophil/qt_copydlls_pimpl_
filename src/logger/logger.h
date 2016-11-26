#ifndef LOGGER_H
#define LOGGER_H

#include <ostream>

extern std::ostream loginfo;
extern struct EndLog {} endlog;
std::ostream& operator<<(std::ostream& stream, EndLog const& e);

#endif
