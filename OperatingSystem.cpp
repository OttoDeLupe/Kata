#include <iostream>
#include <sys/types.h>
#include <fcntl.h>

#include "OperatingSystem.h"

int OperatingSystem::Open(std::string filename)
{
  int fd;
  
  fd = open(filename.c_str(), O_RDONLY);
  return fd;
}

int OperatingSystem::Read(int fd, char* buffer, int count)
{
	return Read(fd, buffer, count);
}
