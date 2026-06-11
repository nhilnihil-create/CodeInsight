#include <cstdio>
int N, M, f[100001], w[100001], b[100001], d[100001];
int F(int x)
{
	if (f[x] == x)
		return x;
	F(f[x]);
	w[x] ^= w[f[x]];
	return f[x] = f[f[x]];
}
int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		f[i] = i;
	for (int i = 1, u, v; i <= M; i++)
	{
		scanf("%d%d", &u, &v);
		d[u]++;
		d[v]++;
		int fu = F(u), fv = F(v);
		if (fu == fv)
		{
			if (w[u] == w[v])
				b[fu] = 1;
		}
		else
		{
			b[fu] |= b[fv];
			w[fv] = w[u] ^ w[v] ^ 1;
			f[fv] = fu;
		}
	}
	int c1 = 0, ce = 0, c = 0;
	for (int i = 1; i <= N; i++)
		if (!d[i])
			c1++;
		else if (F(i) == i)
		{
			c++;
			if (!b[i])
				ce++;
		}
	printf("%lld\n", (long long)c * c + (long long)ce * ce + (long long)N * N - (long long)(N - c1) * (N - c1));
	return 0;
}
