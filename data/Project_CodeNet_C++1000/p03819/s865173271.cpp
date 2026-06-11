#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;
int n, m;
vector <int> seg[N];
int it[N], ans[N];
vector<pair<int, int>> line[N];

void upd(int i, int val) {
	for(; i <= 3e5; i += i & -i) it[i] += val;
}
int get(int i) {
	int ans = 0;
	for(; i; i -= i & -i) ans += it[i];
	return ans;
}

main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		int Left, Right;
		cin >> Left >> Right;
		seg[Left].push_back(Right);
	}
	for(int i = 1; i <= m; ++i) ans[i] = n;
	for(int i = 1; i <= m; ++i) {
		for(int j = 0; j <= m; j += i) {
			line[j + 1].push_back(make_pair(min(m, i + j - 1), i));
		}
	}
	for(int i = m; i >= 1; --i) {
		for(auto &v : seg[i]) upd(v, 1);
		for(auto &v : line[i]) ans[v.second] -= get(v.first);	
	}
	for(int i = 1; i <= m; ++i) cout << ans[i] << '\n';
}