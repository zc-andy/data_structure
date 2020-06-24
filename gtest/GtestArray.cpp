#include "Array.h"
#include "gtest/gtest.h"

namespace 
{
	class TestArray : public testing::Test
	{
		void SetUp() override
		{};

		void TearDown() override
		{};
	};
}

TEST_F(TestArray, TEST_ARRAY)
{
	Array arr;
	char arr_src[] = "1234567890";
	ASSERT_EQ(DS_OK, arr.TurnLeftArray(arr_src, 10, 4));
	ASSERT_STREQ("5678901234", arr_src);
}
