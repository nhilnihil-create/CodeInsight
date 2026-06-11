//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")


using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 200000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000010;
const ll LOG = 25;

int n, Grundy[N];
vi G[N];

void DFS(int v, int p = 0){
	for (auto u:G[v]){
		if (u == p) continue;
		DFS(u, v);
		Grundy[v] ^= (1 + Grundy[u]);
	}
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n - 1; i++){
		int v, u;
		cin >> v >> u;
		G[v].pb(u), G[u].pb(v);
	}
	DFS(1);
	cout << (Grundy[1] == 0?"Bob":"Alice");










	return 0;
}
