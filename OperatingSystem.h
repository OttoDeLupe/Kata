#pragma once

#include "IOperatingSystem.h"

class OperatingSystem : public IOperatingSystem
{
 public:
  int Open(std::string filename);
  int Read(int fd, char* buffer, int count);	

};
