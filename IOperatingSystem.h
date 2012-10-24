#pragma once

#include <iostream>

class IOperatingSystem 
{
 public:
  virtual int Open(std::string filename) = 0;
  virtual int Read(int fd, char* buffer, int count) = 0;

};
