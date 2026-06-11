#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;

const int N = 1e5+6;
int n, ar[N]; bool ok = true;
vector <int> adj[N];

int dfs(int v, int p){
  if (p != -1 && adj[v].size() == 1) return ar[v];
  int sum = 0, mx = 0;
  for (auto u : adj[v]){
    if (u == p) continue;
    int tmp = dfs(u, v);
    sum += tmp;
    mx = max(mx, tmp);
  }
  if (sum > ar[v]*2 || ar[v] > sum || mx > ar[v]) ok = false;
  return ar[v]*2 - sum;
}

signed main(){
	cin >> n;
	for (int i=1; i<=n; i++) cin >> ar[i];
	if (n == 2){
		if (ar[1] == ar[2]) cout << "YES"; else cout << "NO";
		return 0;
	}
	for (int i=1; i<n; i++){
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int d;
	bool ans = false;
	for (int i=1; i<=n; i++){
		if (adj[i].size() >= 2){
			d = i;
			break;
		} 
	}
	ans = (dfs(d, -1) == 0 && ok);
	if (ans) cout << "YES"; else cout << "NO";
}