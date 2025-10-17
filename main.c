#include "castrum.h"

void test_foo(void)
{
	char i[] = {'a', 'b', 'c'}, j[] = {'a', 'b', 'c'};

	// ASSERT_ARR_NE(i, j, 3);
	char *s1 = "h3llo", *s2 = "hello";
	ASSERT_MEM_EQ(s1, s2, 5);
	
}

int main(void)
{
	RUN_TEST(test_foo);
}
