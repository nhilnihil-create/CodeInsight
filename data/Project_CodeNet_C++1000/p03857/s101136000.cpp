#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define ld long double
#define pb push_back
#define all(x) (x).begin(), (x).end()
template <typename T> using ord_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5 + 123;
int n, m[2], used[2][N], comp[N], num, ans[N], cnt[N];
vector <int> g[2][N], vec;

void dfs(int v) {
	used[0][v] = 1;
	comp[v] = num;
	for (int to : g[0][v]) {
		if (used[0][to]) continue;
		dfs(to);
	}
}

void go(int v) {
	vec.pb(v);
	used[1][v] = 1;
	for (int to : g[1][v]) {
		if (used[1][to]) continue;
		go(to);
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
	#endif
	
	cin >> n >> m[0] >> m[1];
	for (int i = 0; i < 2; i++) {
		while (m[i]--) {
			int x, y;
			cin >> x >> y;
			g[i][x].pb(y);
			g[i][y].pb(x);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!used[0][i]) {
			num++;
			dfs(i);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (!used[1][i]) {
			vec.clear();
			go(i);
			for (int j : vec)
				cnt[comp[j]]++;
			for (int j : vec)
				ans[j] = cnt[comp[j]];
			for (int j : vec)
				cnt[comp[j]]--;
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
}
