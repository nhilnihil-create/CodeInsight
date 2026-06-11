#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	long a, b;
	scanf("%ld%ld", &a,&b);
	if (a > 0 && b > 0)
	{
		printf("Positive\n");
		return 0;
	}
	if (a <= 0 && b >= 0)
	{
		printf("Zero\n");
		return 0;
	}
	if (a < 0 && b < 0)
	{
		if (labs(a - b) % 2)
			printf("Positive\n");
		else
			printf("Negative\n");
		return 0;
	}
	return (0);
}
