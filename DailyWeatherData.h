#pragma once

#include "IOperatingSystem.h"
#include "IDailyWeatherData.h"

class DailyWeatherData : public IDailyWeatherData
{
 public:
	DailyWeatherData(IOperatingSystem& os);

	int Read(int recordNumber);

private:
	IOperatingSystem& _os;
	std::string _filename;
	int _recordLength;

	int _day;
	int _maxTemp;
	int _minTemp;
	int _avTemp;
	int _hdDay;
	float _avDP;
	float _1HrP;
	float _totalPcpn;
	char _wxType[5];
	int _pDir;
	float _avSp;
	int _dir;
	int _maxS;
	float _skyC;
	int _maxR;
	int _minR;
	float _avSLP;
};
