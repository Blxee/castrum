#include "castrum.h"

void test_foo(void)
{
	char i[] = {'a', 'b', 'c'}, j[] = {'a', 'b', 'c'};

	ASSERT_ARR_NE(i, j, 3);
	char *s1 = "hello", *s2 = "hello";
	ASSERT_STR_NE(s1, s2)
}

int main(void)
{
	RUN_TEST(test_foo);
}
