//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimise ("ofast")
#pragma GCC optimise("unroll-loops")
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 200000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000000000000000;
const ll LOG = 25;

int n, a[N];
vi G[N];

void DFS(int v, int p = 0){
	if (G[v].size() == 1) return;
	int sm = 0;
	int mx = 0;
	for (auto u:G[v]){
		if (u == p) continue;
		DFS(u, v);
		mx = max(mx, a[u]);	
		sm += a[u];
	}
	int Max = 0;
	if (mx > sm - mx){
		Max = sm - mx;
	}else{
		Max = sm / 2;	
	}
	if (sm < a[v]){
		cout << "NO";
		exit(0);
	}

	
	if (a[v] - (sm - a[v]) < 0){
		cout << "NO";
		exit(0);
	}
	if (Max < sm - a[v]){
		cout << "NO";
		exit(0);
	}
	a[v] -= sm - a[v];
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n - 1; i++){
		int v, u;
		cin >> v >> u;
		G[v].pb(u);
		G[u].pb(v);
	}
	if (n == 2) return cout << (a[1] == a[2] ? "YES" : "NO"), 0;
	int root = 0;
	for (int i = 1; i <= n; i++){
		if (G[i].size() != 1){
			DFS(i);
			root = i;
			break;
		}
	}	
	return cout << (a[root] ? "NO" : "YES"), 0;










	return 0;
}
