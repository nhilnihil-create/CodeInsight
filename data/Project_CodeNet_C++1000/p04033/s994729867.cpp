#include <stdio.h>

int	main()
{
	int	a, b;
	int	ans;

	ans = 0;
	scanf("%d %d\n", &a, &b);
	if (a > 0)
		ans = 1;
	else if (a <= 0 && b >= 0)
		ans = 0;
	else
	{
		if ((b - a) % 2)
			ans = 1;
		else
			ans = -1;
	}
	if (ans == 1)
		printf("Positive\n");
	else if (ans == 0)
		printf("Zero\n");
	else if (ans == -1)
		printf("Negative\n");
	return (0);
}