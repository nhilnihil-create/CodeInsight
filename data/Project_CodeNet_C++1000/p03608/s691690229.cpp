#include <stdio.h>
#include <algorithm>
using namespace std;

#define INF 1e8

int a[222][222], r[11], R, ans = INF;

void update(void)
{
    int i, sum = 0;

    for (i = 1; i < R; i++)
		sum += a[r[i]][r[i + 1]];

    ans = min(ans, sum);
}

int main(void)
{
	// freopen("input.txt", "r", stdin);

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

	sort(r + 1, r + R + 1);
	do {
		update();
	} while (next_permutation(r + 1, r + R + 1));

	printf("%d" ,ans);
	return 0;
}
