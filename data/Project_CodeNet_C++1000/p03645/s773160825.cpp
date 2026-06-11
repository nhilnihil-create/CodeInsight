#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int n, m;
void solve() {
	cin >> n >> m;
	map<int, bool> ok;
	pair<int, int> a[m];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		if (u > v) swap(u, v);
		if (u == 1) {
			ok[v] = true;
		}
		a[i].first = u;
		a[i].second = v;
	}
	for (int i = 0; i < m; i++) {
		if (a[i].second == n && ok[a[i].first]) {
			cout << "POSSIBLE";
			return;
		}
	}
	cout << "IMPOSSIBLE";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
	int T = 1; 
    //cin >> T;
    while(T--) solve();
}