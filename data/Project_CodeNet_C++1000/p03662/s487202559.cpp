#include <bits/stdc++.h>
#define int long long
#define range(i, a, b) for(auto i = (a); i < (b); i++)
#define rep(i, a) range(i, 0, a)
#define all(a) (a).begin(),(a).end()
using namespace std;
const int INF = sizeof(int) == sizeof(long long) ? 1000000000000000000LL : 1000000000;
const int MOD = 1000000007;
const long double EPS = 1e-8;

void dfs(int n, vector <vector <int>>& G, vector <bool>& used, vector <int>& dist,
				 int turn, int cnt = 0){
	for (const auto& i : G[n]) {
		if (used[i]) continue;
		used[i] = true;
		dist[i] = cnt + 1;
		dfs(i, G, used, dist, turn, cnt + 1);
	}
	return;
}

signed main() {
	int n;
	cin >> n;
	vector <vector <int>> G(n);
	rep (i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector <vector <bool>> used(2, vector <bool> (n, false));
	used[0][0] = used[1][n - 1] = true;
	vector <vector <int>> dist(2, vector <int> (n));
	int fen = 0, snu = 0;
	rep (i, 2) dfs(i ? n - 1 : 0, G, used[i], dist[i], i);
	rep (i, n) {
		if (i == 0 || i == n - 1) continue;
		(dist[0][i] <= dist[1][i] ? fen : snu) += 1;
	}
	cout << (fen > snu ? "Fennec" : "Snuke") << endl;
	return 0;
}
