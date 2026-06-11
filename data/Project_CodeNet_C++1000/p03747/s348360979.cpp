#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
int n, m, s[Maxn], rk[Maxn], pos[Maxn];
long long t, c;
int main()
{
	scanf("%d%d%lld", &n, &m, &t);
	for (int i = 0; i < n; i++)
	{
		int opt;
		long long tmp;
		scanf("%d%d", &s[i], &opt);
		if (opt == 2) tmp = s[i] - t;
		else tmp = s[i] + t;
		(c += tmp / m) %= n;
		if (tmp % m < 0) (c += n - 1) %= n;
		pos[i] = (tmp % m + m) % m;
		rk[i] = i;
	}
	sort(pos, pos + n);
	(c += n) %= n;
	for (int i = c; i < n; i++)
		printf("%d\n", pos[i]);
	for (int i = 0; i < c; i++)
		printf("%d\n", pos[i]);
	return 0;
}