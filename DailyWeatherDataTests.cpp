#include <string>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "IOperatingSystem.h"

#include "DailyWeatherData.h"

using namespace ::testing;

class MockOperatingSystem : public IOperatingSystem
{
public:
	MOCK_METHOD3(Read, int(int, char*, int));
	MOCK_METHOD1(Open, int(std::string));
};

class DailyWeatherDataTests : public testing::Test
{
public:
	DailyWeatherDataTests() : _dailyWeather(_os)
		{
		}

	void SetUp()
		{
			ON_CALL(_os, Open(_))
				.WillByDefault(Return(42));

			ON_CALL(_os, Read(_,_,_))
				.WillByDefault(Return(89));
		}

protected:
	NiceMock<MockOperatingSystem> _os;
	DailyWeatherData _dailyWeather;
  
};

TEST_F(DailyWeatherDataTests, ReadOpensFile)
{
	EXPECT_CALL(_os, Open(_))
		.Times(1);

	_dailyWeather.Read(0);
}

TEST_F(DailyWeatherDataTests, ReadOpensCorrectFile)
{
	EXPECT_CALL(_os, Open("weather.dat"))
		.Times(1);

	_dailyWeather.Read(0);
}

TEST_F(DailyWeatherDataTests, ReadReturnsNegativeNumberWhenOpenFails)
{
	NiceMock<MockOperatingSystem> os;
	DailyWeatherData dailyWeather(os);

	ON_CALL(os, Open(_))
		.WillByDefault(Return(-1));
	
	ASSERT_GT(0, dailyWeather.Read(0));
}

TEST_F(DailyWeatherDataTests, ReadCallsOperatingSystemRead)
{
	EXPECT_CALL(_os, Read(_,_,_))
		.Times(1);

	_dailyWeather.Read(12);
}

TEST_F(DailyWeatherDataTests, ReadReturnsNumberOfBytesRead)
{
	ASSERT_EQ(89, _dailyWeather.Read(32));
}


TEST_F(DailyWeatherDataTests, ReadReturnsDifferentNumberOfBytesRead)
{
	ON_CALL(_os, Read(_,_,_))
		.WillByDefault(Return(42));

	ASSERT_EQ(42, _dailyWeather.Read(32));
}


TEST_F(DailyWeatherDataTests, ReadCallsOperatingSystemReadWithFDReturnedByOpen)
{
	ON_CALL(_os, Open(_))
		.WillByDefault(Return(19));

	EXPECT_CALL(_os, Read(19,_,_))
		.Times(1);

	_dailyWeather.Read(32);
}

TEST_F(DailyWeatherDataTests, ReadCallsOperatingSystemReadWithDifferentFDReturnedByOpen)
{
	ON_CALL(_os, Open(_))
		.WillByDefault(Return(45));

	EXPECT_CALL(_os, Read(45,_,_))
		.Times(1);

	_dailyWeather.Read(32);
}


// reading the nth record results in a complete record object being filled out
// Need an ACTION() to populate a passed buffer as if _os.Read() did it

// reading an incomplete record results in an exception

// reading a non existant record results in an exception

// able to use getters to retrieve individual record elements
