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

const int MAXN = 100 * 1000 + 10, MAXD = 13;
int n, m, 
    dis, 
    col, 
    ans[MAXN]; 

queue <int> q;
vector <pair<pii, int>> que;
vector <int> adj[MAXN];

int mark[MAXN];

void bfs(int r)
{
	if (mark[r] >= dis)
		return;

	q.push(r);
	mark[r] = dis;
	while (sz(q))
	{
		int u = q.front();
		q.pop();
		if (!ans[u])
			ans[u] = col;

		for (int v : adj[u])
			if (mark[v] < mark[u] - 1)
			{
				mark[v] = mark[u] - 1;
				q.push(v);
			}
	}
}

int32_t main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i ++)
	{
		int u, v;
		cin >> u >> v;
		u --, v --;
		adj[u].PB(v);
		adj[v].PB(u);
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i ++)
	{
		int v, d, c;
		cin >> v >> d >> c;
		v --;
		que.PB(make_pair(pii(v, d), c));
	}

	memset(mark, -1, sizeof mark);
	reverse(all(que));
	for (auto p : que)
	{
		dis = p.F.S;
		col = p.S;
		bfs(p.F.F);
	}

	for (int i = 0; i < n; i ++)
		cout << ans[i] << "\n";

	return 0;
}
