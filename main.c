#include "castrum.h"

int main(void)
{
	ASSERT_TRUE(34);
	float i = 0;
	printf("%s\n", _Generic(i, int: "iiinnntt", float: "floaat"));
}
