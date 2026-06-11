#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define fastcin() ios_base::sync_with_stdio(0); cin.tie(0)
#define all(x) (x).begin(), (x).end()
#define heap priority_queue
using namespace std;
typedef pair<int, int> ii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int maxn = 200, INF = 1e18; 
vector<pair<ii, int> > adj[maxn]; 

int dis[maxn], n, m; 
bool vis[1050]; 

void dijk(int s) {
	vector<int> g[maxn]; 
	for(int i = 1; i <= n; i++) dis[i] = INF; 
	dis[s] = 0; 
	heap<ii, vector<ii>, greater<ii>> pq; 
	pq.push({0, s}); 
	while(!pq.empty()) {
		ii T = pq.top(); pq.pop(); 
		int u = T.se, d = T.fi; 
		if(d > dis[u]) continue; 
		for(auto v : adj[u]) {
			if(dis[v.fi.fi] > d + v.fi.se) {
				dis[v.fi.fi] = d + v.fi.se; 
				g[v.fi.fi].clear(); 
				pq.push({d + v.fi.se, v.fi.fi});  
			}
			if(dis[v.fi.fi] == d + v.fi.se) 
				g[v.fi.fi].pb(v.se); 
		}
	}
	for(int i = 1; i <= n; i++) 
		for(auto x : g[i]) 
			vis[x] = 1; 
}

signed main()
{
	cin >> n >> m; 
	for(int i = 1; i <= m; i++) {
		int u, v, w; 
		cin >> u >> v >> w; 
		adj[u].pb({{v, w}, i}); 
		adj[v].pb({{u, w}, i}); 
	}
	for(int i = 1; i <= n; i++) dijk(i); 
	int ans = 0; 
	for(int i = 1; i <= m; i++) 	
		ans += (!vis[i]); 
	cout << ans; 
}
