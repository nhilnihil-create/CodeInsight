#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <tuple>
#include <string.h>
#include <math.h>
#include <random>
#include <functional>
#include <assert.h>
#include <math.h>

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int dist[306][306];

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &dist[i][j]);

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (dist[i][j] + dist[j][k] < dist[i][k])
				{
					printf("-1\n");
					return 0;
				}
			}
		}
	}

	i64 ans = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			bool hasMid = false;

			for (int k = 1; k <= n; k++)
			{
				if (k == i || k == j)
					continue;

				if (dist[i][k] + dist[k][j] == dist[i][j])
					hasMid = true;
			}

			if (!hasMid)
				ans += dist[i][j];
		}
	}

	printf("%lld\n", ans);

	return 0;
}