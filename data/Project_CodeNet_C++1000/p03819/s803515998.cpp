#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
const int maxm = 1e5 + 10;
int n, m, g;
int ans[maxm], delta[maxm];
struct seg
{
	int l, r;
}a[maxn];
int main()
{
	scanf("%d%d", &n, &m);
	g = sqrt(m);
	for(int i = 1; i <= n; ++i)	
	{
		scanf("%d%d", &a[i].l, &a[i].r);
		--a[i].l;
	}
	for(int i = 1; i <= g; ++i)
	{
		for(int j = 1; j <= n; ++j)
			if(a[j].l / i != a[j].r / i)
				++ans[i];
	}
	for(int i = m / (g + 1); ~i; --i)
	{
		for(int j = 1; j <= n; ++j)
		{
			int l = max(g + 1, a[j].r / (i + 1) + 1) , r = i == 0 ? m : a[j].l / i;
			if(l > r) continue;
			delta[l]++;
			delta[r + 1]--;
		}
	}
	for(int i = g + 1; i <= m; ++i)
	{
		delta[i] += delta[i - 1];
		ans[i] = n - delta[i];
	}
	for(int i = 1; i <= m; ++i)
		printf("%d ", ans[i]);
	return 0;
}