#include "castrum.h"

void test_foo(void)
{
	int i = 1, j = 3;
	ASSERT_TRUE(1);
	ASSERT_TRUE(1);
	ASSERT_TRUE(1);
	ASSERT_LE(-1, 0);
}

int main(void)
{
	RUN_TEST(test_foo);
}
