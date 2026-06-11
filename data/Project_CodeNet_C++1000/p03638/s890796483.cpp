#include<stdio.h>
#include<stdlib.h>
#define SWAP(a,b) ((a)^=(b)^=(a)^=(b))
typedef long long ll;
int map[105][105];
int col[10005];
int main(void)
{
	int H, W, N;
	scanf("%d %d %d", &H, &W, &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &col[i]);
	int i, j, m, s = 1, a = 0, b = W - 1;
	i = j = m = 0;
	while (m < N)
	{
		for (int k = 0; k < col[m]; k++) {
			map[i][j] = m + 1;
			if (j == b)
				SWAP(a, b), s = -s, i++;
			else
				j += s;
		}
		m++;
	}
	for (int i = 0; i < H; putchar('\n'),i++)
		for (int j = 0; j < W; j++)
			printf("%d ", map[i][j]);
	return 0;
}