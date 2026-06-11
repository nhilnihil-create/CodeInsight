#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 100000;
const long long inf = 1ll << 61;
typedef pair<int, int> P;
typedef pair<int,P> PP;
typedef pair<int,PP> PPP;
struct edge { int to;  int cost; };

vector<int>G[100006];
int v[100006], d[100006], c[100006];
int dp[100006][11];

void dfs(int V, int D, int C) {
	if (D < 0)return;
	for (int i = D; i <= 10; i++) {
		if (dp[V][i] >= 0) return;
	}
	dp[V][D] = C;
	rep(i, G[V].size()) {
		dfs(G[V][i], D - 1, C);
	}
	return;
}

signed main() {
	int n, m; cin >> n >> m;
	rep(i, m) {
		int a, b; cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int q; cin >> q;
	rep(i, q) {
		cin >> v[i] >> d[i] >> c[i];
		v[i]--;
	}
	rep(i, n)rep(j, 11)dp[i][j] = -1;
	for (int i = q - 1; i >= 0; i--) {
		dfs(v[i], d[i], i);
	}

	rep(i, n) {
		int ac = 0;
		rep(j, 11) {
			if (dp[i][j] != -1) {
				ac = c[dp[i][j]];
				break;
			}
		}
		cout << ac << endl;
	}
}