// https://atcoder.jp/contests/abc051/tasks/abc051_d
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod = 1000 * 1000 * 1000 + 7;
const int INF = 1000 * 1000 * 1000;
const ll LINF = (ll)INF * INF;

#define dbg(x) cerr << #x << " = " << (x) << endl;
#define dbg2(x, y) cerr << '{' << #x << ", " << #y << "} = {" << (x) << ", " << (y) << '}' << endl;
#define dbgp(x) cerr << #x << " = {" << (x).first << ", " << (x).second << '}' << endl;
#define dbgr(s, f) {cerr << #s << ": "; for (auto _ = (s); _ != (f); _++) { cerr << *_ << ' '; }; cerr << endl;}
#define dbgv(x) {cerr << #x << ": "; for (auto _ = (x).begin(); _ != (x).end(); _++) { cerr << *_ << ' '; }; cerr << endl;}
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define fast_io ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fr first
#define sc second

#define MAXN 150
#define MAXM 1050

int n;
vector<int> adj[MAXN];
int eto[MAXM], efrom[MAXM], ew[MAXM];
set<pii> s;
int dist[MAXN];

void dij(int r)
{
	fill(dist, dist + n + 10, INF);
	dist[r] = 0;
	FOR(i, 1, n + 1)
	{
		s.insert({dist[i], i});
	}
	while (!s.empty())
	{
		int v = s.begin() -> second;
		s.erase(s.begin());
		for (int e : adj[v])
		{
			int u = eto[e] ^ efrom[e] ^ v;
			auto it = s.find({dist[u], u});
			if (it == s.end())
				continue;
			int nd = dist[v] + ew[e];
			if (nd < dist[u])
			{
				s.erase(it);
				dist[u] = nd;
				s.insert({dist[u], u});
			}
		}
	}
}

int main(void)
{
	int m;
	cin >> n >> m;
	FOR(i, 0, m)
	{
		int ai, bi, ci;
		cin >> ai >> bi >> ci;
		adj[ai].pb(i);
		adj[bi].pb(i);
		eto[i] = bi;
		efrom[i] = ai;
		ew[i] = ci;
	}
	int ans = 0;
	FOR(i, 0, m)
	{
		// clearing stuff

		int w = ew[i];
		ew[i] = INF;
		dij(eto[i]);
		ew[i] = w;
		if (dist[efrom[i]] < w)
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}

