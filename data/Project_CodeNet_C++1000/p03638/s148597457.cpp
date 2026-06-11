#include<stdio.h>
int a[101][101];
int main()
{
	int h, w;
	int n;
	int tmp;
	scanf("%d %d", &h, &w);
	scanf("%d", &n);
	int j = 1, k = 1;
	int flag = 1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &tmp);
		while (tmp > 0)
		{
			for (j; j <= h;)
			{
				if (flag)
				{
					for (k; k <= w && tmp; k++)
					{
						a[j][k] = i;
						tmp--;
					}
					if (k == w + 1)
					{
						k = w;
						flag = 0;
						j++;
					}
				}
				if (!flag)
				{
					for (k; k >= 1 && tmp; k--)
					{
						a[j][k] = i;
						tmp--;
					}
					if (k == 0)
					{
						k = 1;
						flag = 1;
						j++;
					}
				}
				if (!tmp) break;
			}
		}
	}
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}