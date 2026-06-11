#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll MOD = 1000000007LL;
vector<int> G[100000];
int dp[100000][11];
int v[100000], d[100000], c[100000];
void solve(int x, int dist, int t) {
	if (dp[x][dist] != -1) return;
	dp[x][dist] = t;
	if (dist == 0) return;
	solve(x, dist - 1, t);
	for (int to : G[x]) {
		solve(to, dist - 1, t);
	}
}
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> v[i] >> d[i] >> c[i];
		v[i]--;
	}
	memset(dp, -1, sizeof(dp));
	for (int i = Q - 1; i >= 0; i--) {
		solve(v[i], d[i], i);
	}
	for (int i = 0; i < N; i++) {
		if (dp[i][0] == -1) cout << 0 << endl;
		else cout << c[dp[i][0]] << endl;
	}
}