#pragma once

#include <iostream>

class IDailyWeatherData
{
 public:
	virtual int Read(int recordNumber) = 0;
};
