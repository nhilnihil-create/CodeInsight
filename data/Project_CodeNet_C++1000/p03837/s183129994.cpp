#include <stdio.h>
#include <algorithm>
using namespace std;

#define INF 1e9

int a[111][111], b[111][111];

int main(void)
{
	int n, m, i, j, k, ans = 0;

	scanf("%d %d" ,&n, &m);

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i != j)
				a[i][j] = INF;

	while (m--)
	{
		int x, y, z;

		scanf("%d %d %d" ,&x, &y, &z);

		a[x][y] = a[y][x] = b[x][y] = b[y][x] = z;
	}

	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);

	for (i = 1; i < n; i++)
		for (j = i + 1; j <= n; j++)
			if (a[i][j] < b[i][j])
				++ans;

	printf("%d" ,ans);
	return 0;
}