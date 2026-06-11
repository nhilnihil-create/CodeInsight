#include<stdio.h>
int main()
{
	int a, b, d;
	scanf("%d%d%d", &a, &b, &d);
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			int s = i + j, t = i + b - j;
			if (s % (2 * d) < d)
			{
				if (t % (2 * d) < d)printf("R");
				else printf("G");
			}
			else
			{
				if (t % (2 * d) < d)printf("Y");
				else printf("B");
			}
		}
		printf("\n");
	}
}