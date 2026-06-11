#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const int N = 1e5 + 7;

int n, m, q, u, v;
int x[N], dis[N], c[N], ans[N];
bool vis[13][N];
vector <int> edge[N];

void solve(int u, int d, int col){
	if(vis[d][u]) return;
	queue < pair <int, int> > q;
	q.push(mp(u, d));
	for(int i = d; i >= 0; i--) vis[i][u] = true;
	while(!q.empty()){
		int cur = q.front().fi, ds = q.front().se;
		q.pop();
		if(!ans[cur]) ans[cur] = col;
		if(ds == 0) continue;
		for(int v : edge[cur]){
			if(!vis[ds - 1][v]){
				for(int i = ds - 1; i >= 0; i--) vis[i][v] = true;
				q.push(mp(v, ds - 1));
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	cin >> q;
	for(int i = 1; i <= q; i++){
		cin >> x[i] >> dis[i] >> c[i];
	}
	for(int i = q; i >= 1; i--){
		solve(x[i], dis[i], c[i]);
	}
	for(int i = 1; i <= n; i++) cout << ans[i] << "\n";
}
