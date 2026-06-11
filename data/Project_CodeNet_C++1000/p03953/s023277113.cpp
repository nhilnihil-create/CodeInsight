#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n, m;
ll k;
int p[maxn];
ll x[maxn], d[maxn];
bool vis[maxn];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%lld", &x[i]);
	for(int i = 1; i < n; ++i) d[i] = x[i + 1] - x[i];
	scanf("%d%lld", &m, &k);
	for(int i = 1; i < n; ++i) p[i] = i;
	for(int i = 1; i <= m; ++i)
	{
		int pos;
		scanf("%d", &pos);
		swap(p[pos], p[pos - 1]);
	}
	vector<int> cycle;
	for(int i = 1; i < n; ++i)
		if(!vis[i])
		{
			cycle.clear();
			int cur = i;
			while(!vis[cur])
			{
				vis[cur] = 1;
				cycle.push_back(cur);
				cur = p[cur];
			}
			int pos = k % cycle.size();
			for(int i = 0; i < cycle.size(); ++i)
				p[cycle[i]] = cycle[(i + pos) % cycle.size()];
		}
	/*
	for(int i = 1; i < n; ++i) printf("%d ", p[i]);
	puts("");
	*/
	printf("%lld\n", x[1]);
	ll cur = x[1];
	for(int i = 1; i < n; ++i)
	{
		cur += d[p[i]];
		printf("%lld\n", cur);
	}
	return 0;
}
/*
5
0 1 3 6 10
3 99999999999999
2 3 4
*/
		 
			
			