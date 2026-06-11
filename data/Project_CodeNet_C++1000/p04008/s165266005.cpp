#include <bits/stdc++.h>
#define len(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define chmax(x, v) x = max((x), (v))
#define chmin(x, v) x = min((x), (v))
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int nbElem, distMax;
	cin >> nbElem >> distMax;
	vector<vector<int>> child(nbElem);
	int res = 0;
	for (int i = 0; i < nbElem; ++i) {
		int dir; cin >> dir; --dir;
		if (i == 0 && dir > 0) ++res;
		if (i > 0) { child[dir].push_back(i); }
	}
	function<int(int, int)> dfs = [&] (int node, int par) {
		int md = 1;
		for (int nei : child[node]) {
			chmax(md, dfs(nei,node)+1);
		}
		if (node && md == distMax+(par==0)) {
			++res; return 0;
		}
		return md;
	};
	dfs(0,-1);
	cout << res << "\n";
}
