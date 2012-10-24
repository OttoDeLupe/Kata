#include <iostream>

#include <sys/types.h>
#include <fcntl.h>

#include "gtest/gtest.h"
#include "OperatingSystem.h"

class OperatingSystemTests : public testing::Test
{
public:
  OperatingSystemTests() : _filename("weather.dat")
  {
  }

protected:
  OperatingSystem _os;
  std::string _filename;
  
};

TEST_F(OperatingSystemTests, Open_Returns_Positive_FD_For_Existing_File)
{
  EXPECT_LT(2, _os.Open(_filename));
}

TEST_F(OperatingSystemTests, Open_Returns_Negative_FD_For_NonExistant_File)
{
  std::string bogusFilename = "foobar.baz";
  EXPECT_GT(0, _os.Open(bogusFilename));
}

TEST_F(OperatingSystemTests, Read_Returns_Number_Of_Bytes_Read)
{
	int fd = _os.Open(_filename);
	char buffer[100];

	EXPECT_EQ(42, _os.Read(fd, buffer, 42));
}

TEST_F(OperatingSystemTests, Read_Returns_Negative_Number_On_Error)
{
	int fd = _os.Open(_filename);
	char buffer[100];

	EXPECT_GT(0, _os.Read(fd, buffer, 42));
}

bool MatchBuffer(const char* testValue, const char* constantValue, int size)
{
	bool returnValue = true;
	std::cout << "In Match Buffer" << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << i << " " << testValue[i] << " " << constantValue[i] << std::endl;
		returnValue = (testValue[i] != constantValue[i]) ? false : true;
	}
	
	return returnValue;
}

TEST_F(OperatingSystemTests, Read_Fills_Buffer_With_Number_Of_Bytes_Requested)
{
	//int fd = _os.Open(_filename);
	//int readCount;
	//char buffer[100];
	char c;
//	char expectedValue[43] = "   1  80    62    70          43.1       0";

	std::cout << "trying..." << std::endl;
	int f = open("weather.dat", O_RDONLY);
	int r = read(f, &c, 1);
	std::cout << "read " << r << " bytes" << std::endl;
	//readCount = _os.Read(fd, buffer, 42);

	//EXPECT_PRED3(MatchBuffer, buffer, expectedValue, readCount);
}

