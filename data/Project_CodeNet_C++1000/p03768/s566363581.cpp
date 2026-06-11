#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7, N = 1e5 + 7;

vi G[N];
int vis[N][11], color[N], v[N], d[N], c[N];

void go(int u, int d, int c) {
	if(vis[u][d]) return;
	vis[u][d] = 1;
	if(color[u] == 0) color[u] = c;
	if(d == 0) return;
	for(int v:G[u]) {
		go(v, d - 1, c);
	}
}

signed main()
{
	IO_OP;
	
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	int q;
	cin >> q;
	for(int i = 0; i < q; i++) cin >> v[i] >> d[i] >> c[i];
	for(int i = q - 1; i >= 0; i--) {
		go(v[i], d[i], c[i]);

	}
	for(int i = 1; i <= n; i++) cout << color[i] << endl;
}


