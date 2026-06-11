#include <cstdio>
#include <cmath>

int n, m, k;

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x = floor((double)(i + j) / k);
			int y = floor((double)(i - j) / k);
			if ((x & 1) && (y & 1))
			{
				printf("R");
			}
			if ((x & 1) && ! (y & 1))
			{
				printf("Y");
			}
			if (! (x & 1) && (y & 1))
			{
				printf("G");
			}
			if (! (x & 1) && ! (y & 1))
			{
				printf("B");
			}
		}
		puts("");
	}
	return 0;
}
