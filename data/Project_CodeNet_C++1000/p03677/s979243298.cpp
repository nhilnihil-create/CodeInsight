#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

const int MaxN = 1000000;
const int MaxM = 1000000;

int n, m, a[MaxN + 1];

s64 f[MaxM + 3];

inline void add(int l, int r, int a, int b)
{
	int x = a + (r - l) * b;
	f[l + 0] += a, f[l + 1] -= a;
	f[l + 1] += b, f[r + 1] -= b;
	f[r + 1] -= x, f[r + 2] += x;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		a[i] = getint();

	for (int i = 2; i <= n; ++i)
	{
		int u = a[i - 0];
		int v = a[i - 1];

		if (u > v)
			add(v + 1, u, 0, 1);
		else if (v == m)
			add(1, u, 0, 1);
		else
		{
			int l = m - v;
			add(v + 1, m, 0, 1);
			add(1, u, l, 1);
		}
	}

	for (int i = 2; i <= m; ++i)
		f[i] += f[i - 1];
	for (int i = 2; i <= m; ++i)
		f[i] += f[i - 1];

	s64 res = -*max_element(f + 1, f + m + 1);
	for (int i = 2; i <= n; ++i)
		res += a[i] - a[i - 1] + (a[i] > a[i - 1] ? 0 : m);

	cout << res << endl;

	return 0;
}