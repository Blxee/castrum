#include "castrum.h"

void test_foo(void)
{
	ASSERT_TRUE(1);
	ASSERT_TRUE(1);
	ASSERT_TRUE(1);
	ASSERT_TRUE(0);
	ASSERT_TRUE(0);
}

int main(void)
{
	RUN_TEST(test_foo);
}
