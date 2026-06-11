#include <cstdio>
#include <algorithm>
int N, M, a[100001];
long long x0[100002], x1[100002], O = 1LL << 60;
void add(int x, int y)
{
	if (x < y)
	{
		x0[1] += y - x;
		x0[x + 1] -= y - x;
		x0[y + 1] += y - x;
		x0[M + 1] -= y - x;
		x1[x + 1]--;
		x1[y + 1]++;
		x0[x + 1] += y + 1;
		x0[y + 1] -= y + 1;
	}
	else
	{
		x0[y + 1] += M + y - x;
		x0[x + 1] -= M + y - x;
		x1[x + 1]--;
		x1[M + 1]++;
		x0[x + 1] += M + y + 1;
		x0[M + 1] -= M + y + 1;
		x1[1]--;
		x1[y + 1]++;
		x0[1] += y + 1;
		x0[y + 1] -= y + 1;
	}
}
int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
	for (int i = 1; i < N; i++)
		add(a[i], a[i + 1]);
	for (int i = 2; i <= M; i++)
	{
		x0[i] += x0[i - 1];
		x1[i] += x1[i - 1];
	}
	for (int i = 1; i <= M; i++)
		O = std::min(O, x0[i] + x1[i] * i);
	printf("%lld\n", O);
	return 0;
}
