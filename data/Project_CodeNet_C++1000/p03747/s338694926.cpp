#include <cstdio>
#include <algorithm>
int N, L, T, p[100001], C = 1;
int main()
{
	scanf("%d%d%d", &N, &L, &T);
	for (int i = 1, x, w; i <= N; i++)
	{
		scanf("%d%d", &x, &w);
		if (w == 1)
		{
			int z = (T + x) / L;
			C = (C + z - 1) % N + 1;
			p[i] = (x + T) % L;
		}
		else
		{
			int z = (T - x - 1 + L) / L;
			C = ((C - z - 1) % N + N) % N + 1;
			p[i] = ((x - T) % L + L) % L;
		}
	}
	std::sort(p + 1, p + N + 1);
	for (int i = C; i <= N; i++)
		printf("%d\n", p[i]);
	for (int i = 1; i < C; i++)
		printf("%d\n", p[i]);
	return 0;
}
