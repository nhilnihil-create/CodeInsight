#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define pii pair<int, int>
#define X first
#define Y second
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
const int N = 1e5 + 10;
int n, a[N], k, ans;
int dep[N], vis[N];
vector<int> G[N];

int dfs(int x, int dep)
{
	int ret = dep;
	int nn = G[x].size();
	rep(i, 0, nn - 1)
	{
		int to = G[x][i];
		ret = max(ret, dfs(to, dep + 1));
	}
	if(a[x] != 1 && ret - dep == k - 1)
	{
		ans ++;
		return 0;
	}
	return ret;
}

int main()
{
	n = read();
	k = read();
	rep(i, 1, n)
	{
		a[i] = read();
		if(i != 1) G[a[i]].pb(i);
	}
	if(a[1] != 1) a[1] = 1, ans ++;
	dfs(1, 0);
	cout << ans;
	return 0;
}
