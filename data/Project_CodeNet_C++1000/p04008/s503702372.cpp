#include <bits/stdc++.h>
#define LL long long
#define PB push_back
#define X first
#define Y second
#define INF 1000 * 1000 * 1000
using namespace std;
const LL mod = 1000 * 1000 * 1000 + 7;
const LL ob = (mod + 1) >> 1;
int n , k;
int a[100005];
vector<vector<int> > g(100005);
vector<int> path;
int P[100005];
int deleted[100005];
int kth[100005];
vector<pair<int , int> > v;
void dfs(int u , int p = -1)
{
	v.PB({path.size() , u});
	P[u] = p;
	path.PB(u);
	if(path.size() >= k)
	{
		kth[u] = path[path.size() - k];
	}
	for(auto v : g[u])
	{
		if(v != p)
			dfs(v , u);
	}
	path.pop_back();
}
void dfs2(int u , int p)
{
	deleted[u] = 1;
	for(auto v : g[u])
	{
		if(!deleted[v] && v != p)
		{
			dfs2(v , u);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	cin >> a[0];
	a[0]--;
	for(int i = 1; i < n; i++)
	{
		cin >> a[i];
		a[i]--;
		g[a[i]].PB(i);
		g[i].PB(a[i]);
	}
	int ans = a[0] != 0;
	dfs(0);
	sort(v.begin() , v.end());
	
	while(v.size())
	{
		int u = v.back().Y , d = v.back().X;
		v.pop_back();
		if(deleted[u])
			continue;
		if(d <= k)
			break;
		
		ans++;
		dfs2(kth[u] , P[kth[u]]);
	}
	cout << ans;
}


