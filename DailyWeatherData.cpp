
#include "DailyWeatherData.h"

DailyWeatherData::DailyWeatherData(IOperatingSystem& os) : 
	_os(os), _filename("weather.dat"), _recordLength(89)
{
}

int DailyWeatherData::Read(int recordNumber)
{
	int fd = _os.Open(_filename);
	char foo[_recordLength];

	if (fd < 0)
		return fd;

	return _os.Read(fd, foo, _recordLength);
}
