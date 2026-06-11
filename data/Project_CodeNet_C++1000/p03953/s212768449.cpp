#include <cstdio>
#include <algorithm>
int N, M, ans[100001], bit[100001], tmp[100001];
long long K, a[100001], s[100001];
void MUL(int *a, int *b, int *c)
{
	for (int i = 0; i <= N; i++)
		tmp[i] = a[b[i]];
	std::copy(tmp, tmp + N + 1, c);
}
int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		scanf("%lld", a + i);
	for (int i = 0; i <= N; i++)
	{
		bit[i] = i;
		ans[i] = i;
	}
	scanf("%d%lld", &M, &K);
	for (int i = 1, u; i <= M; i++)
	{
		scanf("%d", &u);
		std::swap(bit[u - 1], bit[u]);
	}
	for (; K; K >>= 1)
	{
		if (K & 1)
			MUL(ans, bit, ans);
		MUL(bit, bit, bit);
	}
	for (int i = 1; i < N; i++)
		a[i] -= a[i + 1];
	for (int i = 1; i <= N; i++)
		s[i] = a[ans[i]];
	for (int i = N - 1; i; i--)
		s[i] += s[i + 1];
	for (int i = 1; i <= N; i++)
		printf("%lld.0\n", s[i]);
	return 0;
}
