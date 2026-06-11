# include<bits/stdc++.h>

using namespace std;

# define int long long
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

const int MAXN = 100 * 1000 + 10;
vector <int> adj[MAXN],
       ans;

bool mark[MAXN];
void dfs(int u)
{
	ans.PB(u);
	mark[u] = true;
	for (int v : adj[u])
		if (!mark[v])
		{
			dfs(v);
			return;
		}
}

int32_t main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	int u, v;
	for (int i = 0; i < m; i ++)
	{
		cin >> u >> v;
		u --, v --;
		adj[u].PB(v);
		adj[v].PB(u);
	}

	mark[u] = mark[v] = true;
	dfs(u);
	reverse(all(ans));
	dfs(v);

	cout << sz(ans) << endl;
	for (int a : ans)
		cout << a + 1 << " ";
	cout << endl;

	return 0;
}
