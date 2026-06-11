#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n;
ll a[maxn];
vector<int> E[maxn];
void no() { puts("NO"); exit(0);}
ll dfs(int x, int fa)
{
	ll sum = 0, Max = 0;
	for(auto v : E[x])
		if(v != fa)
		{
			ll val = dfs(v, x);
			Max = max(Max, val);
			sum += val;
		}
	if(E[x].size() == 1) return a[x];
	ll cur = sum - a[x], lim;
	if(Max >= sum - Max) lim = sum - Max;
	else lim = sum / 2;
	if(cur < 0 || cur > lim) no();
	return a[x] - cur;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	if(n == 2)
	{
		if(a[1] == a[2]) puts("YES");
		else puts("NO");
		return 0;
	}
	for(int i = 1; i < n; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	int rt = 0;
	for(int i = 1; i <= n; ++i)
		if(E[i].size() > 1)
		{
			rt = i;
			break;
		}
	if(dfs(rt, 0)) no();
	puts("YES");
	return 0;
}