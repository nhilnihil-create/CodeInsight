#include <stdio.h>
#include <algorithm>
using namespace std;

#define INF 1e9

int init[111][111], after[111][111];

int main(void)
{
    int n, m, i, j, k, ans = 0;

    scanf("%d %d" ,&n, &m);

    for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i != j)
				after[i][j] = INF;

    while (m--)
	{
        int x, y, z;
        scanf("%d %d %d" ,&x, &y, &z);
        init[x][y] = init[y][x] = after[x][y] = after[y][x] = z;
	}

	for (k = 1; k <= n; k++)
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
                after[i][j] = min(after[i][j], after[i][k] + after[k][j]);

	for (i = 1; i <= n; i++)
		for (j = i + 1; j <= n; j++)
			if (init[i][j] > after[i][j])
				++ans;

	printf("%d" ,ans);
	return 0;
}
