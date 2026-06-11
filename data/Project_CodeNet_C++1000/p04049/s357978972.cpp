# include<bits/stdc++.h>
 
using namespace std;
 
#define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef pair<ll, ll> pll;
 
# define S second
# define F first
# define kill(x) return(cout << x << endl, 0)
# define debug(x) cerr<< #x << " : " << x << endl
# define ddebug(x, y) cerr<< #x << " : " << x  << ", " << #y << " : " << y << endl
# define sz(s) (int)s.size()
# define sq(x) (x) * (x)
# define PB(x) push_back(x)
# define smax(x, y) (x) = max((x), (y))
# define smin(x, y) (x) = min((x), (y))
# define all(x) x.begin(), x.end()
# define SP fixed << setprecision(10)
# define UB upper_bound 

const int MAXN = 2000 + 10;
int n, k;
vector <int> adj[MAXN];
pii edg[MAXN];
int hei[MAXN];

int dfs(int u)
{
	int res = (hei[u] > k / 2);
	for (int v : adj[u])
		if (hei[v] == -1)
		{
			hei[v] = hei[u] + 1;
			res += dfs(v);
		}
	return res;
}

int32_t main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n - 1; i ++)
	{
		int u, v;
		cin >> u >> v;
		u --, v --;
		adj[u].PB(v);
		adj[v].PB(u);
		edg[i] = {u, v};
	}

	int ans = n;
	for (int i = 0; i < n; i ++)
	{
		if (!(k & 1))
		{
			memset(hei, -1, sizeof hei);
			hei[i] = 0;
			smin(ans, dfs(i));
		}
		else if (i != n)
		{
			memset(hei, -1, sizeof hei);
			int u = edg[i].F, v = edg[i].S;
			hei[u] = hei[v] = 0;
			smin(ans, dfs(u) + dfs(v));
		}
	}
	cout << ans << endl;

	return 0;
}
