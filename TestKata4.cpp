#include "gtest/gtest.h"
#include "Kata4.h"

class Kata4Test : public testing::Test
{
public:

protected:
	Kata4 _kata;
};

TEST_F(Kata4Test, DoSomethingDoesSomething)
{
	EXPECT_EQ("Foo", _kata.DoSomething());
}
