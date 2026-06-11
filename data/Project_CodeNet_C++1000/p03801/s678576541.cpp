#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef long long LL;
typedef pair<int, int> pii;

const int maxn = 100005;

pii aa[maxn];
LL ans[maxn];

signed main()
{
//	freopen("main.in", "r", stdin);
//	freopen("main.out", "w", stdout);
	int n;
	scanf("%lld", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%lld", &aa[i].first);
		aa[i].second = i;
	}
	sort(aa + 1, aa + n + 1, greater<pii>());
	int nowid = n;
	for(int i = 1; i <= n; ++i)
	{
		if(aa[i].first != aa[i + 1].first)
		{
			nowid = min(nowid, aa[i].second);
			ans[nowid] += (aa[i].first - aa[i + 1].first) * i;
		}
	}
	for(int i = 1; i <= n; ++i)
		printf("%lld\n", ans[i]);
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}