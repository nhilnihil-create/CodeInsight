#include <bits/stdc++.h>
# define write1 { puts("Yes"); return 0;}
# define write2 { puts("No"); return 0;}
# define INF 100000000
using namespace std;
int n, sum, minn = INF, maxn = -INF;
int a[110000];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		maxn = max(maxn, a[i]);
		minn = min(minn, a[i]);
	}
	if (maxn - minn >= 2) write2
	if (maxn == minn)
	{
		if (maxn == n - 1) write1
		if (maxn * 2 <= n) write1
		else write2
	}
	for (int i = 1; i <= n; i++) if (a[i] == minn) ++sum;
	if (minn < sum) write2
	if (n - sum < 2 * (maxn - sum)) write2
	else write1
	return 0;
}
