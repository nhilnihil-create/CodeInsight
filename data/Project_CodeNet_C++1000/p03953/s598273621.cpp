#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;

const int MaxN = 100000;
const int MaxM = 100000;

int n, m;
s64 nK;

int a[MaxN + 1], d[MaxN + 1];

int rep[MaxN + 1];
int ret[MaxN + 1];

inline int work(int *a, int *b)
{
	static int c[MaxN + 1];
	for (int i = 1; i <= n; ++i)
		c[i] = a[b[i]];
	for (int i = 1; i <= n; ++i)
		a[i] = c[i];
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		d[i] = a[i] - a[i - 1];
	}

	cin >> m >> nK;
	for (int i = 1; i <= n; ++i)
		rep[i] = ret[i] = i;
	for (int i = 1, x; i <= m; ++i)
	{
		scanf("%d", &x);
		swap(rep[x], rep[x + 1]);
	}

	for (s64 i = nK; i; i >>= 1)
	{
		if (i & 1)
			work(ret, rep);
		work(rep, rep);
	}

	work(d, ret);

	s64 res = 0;
	for (int i = 1; i <= n; ++i)
		printf("%lld\n", res += d[i]);

	return 0;
}