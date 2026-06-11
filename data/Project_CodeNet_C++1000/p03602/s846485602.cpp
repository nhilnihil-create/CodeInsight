#include <cstdio>

/**
	I'm not sure whether this works or not.
*/

int N;
int cost[300][300];
bool mark[300][300];

int main(void)
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int n = 0; n < N; ++n)
		for (int m = 0; m < N; ++m)
			scanf("%d", &(cost[n][m]));
	for (int n = 0; n < N; ++n)
		for (int m = n + 1; m < N; ++m)
		{
			mark[n][m] = true;
			for (int k = 0; k < N; ++k)
			{
				if (k == n || k == m)
					continue;
				if (cost[n][m] == cost[n][k] + cost[k][m])
					mark[n][m] = false;
				else if (cost[n][m] > cost[n][k] + cost[k][m])
				{
					printf("-1");
					return 0;
				}
			}
		}
	long long sum = 0;
	for (int n = 0; n < N; ++n)
		for (int m = n + 1; m < N; ++m)
			if (mark[n][m])
				sum += cost[n][m];
	printf("%lld", sum);
	return 0;
}