#include <stdio.h>
#include <algorithm>
using namespace std;

#define INF 1e8

int a[222][222], r[11], check[11], prm[11], R, ans = INF;

void update(void)
{
    int i, sum = 0;

    for (i = 1; i < R; i++)
		sum += a[prm[i]][prm[i + 1]];

    ans = min(ans, sum);
}

void permutation(int lev)
{
	if (lev > R)
	{
		update();
		return;
	}

    int i;

    for (i = 1; i <= R; i++)
		if (!check[i])
		{
			check[i] = 1;
			prm[lev] = r[i];
			permutation(lev + 1);
			check[i] = 0;
		}
}

int main(void)
{
    int N, M, i, j, k;

    scanf("%d %d %d" ,&N, &M, &R);
	for (i = 1; i <= R; i++)
		scanf("%d" ,&r[i]);

    for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
            if (i != j)
				a[i][j] = INF;

    while (M--)
	{
		int x, y, z;

		scanf("%d %d %d" ,&x, &y, &z);

        a[x][y] = a[y][x] = min(a[x][y], z);
	}

    for (k = 1; k <= N; k++)
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++)
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);

	permutation(1);

	printf("%d" ,ans);
	return 0;
}