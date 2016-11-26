#ifndef COUT_LOGGER_H
#define COUT_LOGGER_H

#include <sstream>

class CoutLogger : public std::stringbuf
{
public:

  virtual ~CoutLogger();

protected:

  virtual int sync() override;

};

#endif
