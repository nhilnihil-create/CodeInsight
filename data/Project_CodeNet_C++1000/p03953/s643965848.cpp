#pragma GCC optimize("Ofast")
#pragma GCC target("sse3","sse2","sse")
#pragma GCC target("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target("f16c")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#pragma GCC diagnostic error "-std=c++14"
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define MX 100005

using namespace std;

typedef long long ll;

ll x[MX];
ll seq[MX], det[MX], tar[MX], ans[MX];
ll n, m;
ll k;
ll id[MX], to[MX];
ll vis[MX], cnt;
vector<ll> src[MX], cyc[MX];

void dfs(ll x)
{
	vis[x] = 1;
	src[cnt].push_back(x);
	cyc[cnt].push_back(x);
	if(!vis[to[x]]) dfs(to[x]);
}

int main()
{
	scanf("%lld", &n);
	for(int i=1; i<=n; i++) scanf("%lld", &x[i]), det[i] = x[i]-x[i-1];
	scanf("%lld%lld", &m, &k);
	for(int i=1; i<=m; i++) scanf("%lld", &seq[i]);
	for(int i=1; i<=n; i++) id[i] = i;
	for(int i=1; i<=m; i++) swap(id[seq[i]], id[seq[i]+1]);
	for(int i=1; i<=n; i++) to[id[i]] = i;
	for(int i=1; i<=n; i++) if(!vis[i]) cnt++, dfs(i);
	for(int i=1; i<=cnt; i++)
	{
		int t = k % cyc[i].size();
		cyc[i].insert(cyc[i].end(), cyc[i].begin(), cyc[i].begin()+t);
		cyc[i].erase(cyc[i].begin(), cyc[i].begin()+t);
	}
	for(int i=1; i<=cnt; i++)
		for(int j=0; j<src[i].size(); j++)
			tar[cyc[i][j]] = det[src[i][j]];
	for(int i=1; i<=n; i++) ans[i] = ans[i-1] + tar[i];
	for(int i=1; i<=n; i++) printf("%lld\n", ans[i]);
	return 0;
}