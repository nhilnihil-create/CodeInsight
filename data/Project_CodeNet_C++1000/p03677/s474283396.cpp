#include <cstdio>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;
const int MAXN = 1e5 + 10;

int a[MAXN];
long long cnt[MAXN << 1];
int n, m;
inline void _read(int &x)
{
	x = 0;
	register char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
}

int main()
{
	_read(n), _read(m);
	for (register int i = 1; i <= n; ++i) _read(a[i]);
	
	long long tot = 0;
	for (register int i = 1, l, r; i < n; ++i)
	{
		l = a[i];
		r = a[i + 1];
		if (l > r) r += m;
		tot += r - l;
		if (r - l > 1)
		{
			cnt[l + 2]++;
			cnt[r + 1] -= r - (l + 2) + 2;
			cnt[r + 2] += r - (l + 2) + 1;
		}
	}
	for (register int i = 1; i <= m * 2; ++i) cnt[i] += cnt[i - 1];
	for (register int i = 1; i <= m * 2; ++i) cnt[i] += cnt[i - 1];
	register long long ans = tot;
	for (register int i = 1; i <= m; ++i) ans = min(ans, tot - cnt[i] - cnt[i + m]);
	return printf("%lld", ans), 0;
}