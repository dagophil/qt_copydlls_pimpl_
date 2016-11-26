#include "cout_logger.h"

#include <iostream>

CoutLogger::~CoutLogger()
{
  auto remain = str();
  if (remain.size() > 0)
  {
    std::cout << remain;
    std::cout.flush();
  }
}

int CoutLogger::sync()
{
  std::cout << str();
  std::cout.flush();
  str("");
  return std::stringbuf::sync();
}
