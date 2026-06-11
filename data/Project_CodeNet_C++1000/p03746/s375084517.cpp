#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

const double PI = 3.1415926535897932384626433832795;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { -1, 0, 1, 0 };

int gcd(int x, int y) { return y ? gcd(y, x % y) : abs(x); }
ll gcd(ll x, ll y) { return y ? gcd(y, x % y) : abs(x); }
int lcm(int x, int y) { return x / gcd(x, y) * y; }
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }

int n, m;
vector<vector<int>> g;
vector<bool> used;

void dfs(vector<int> &path, int i) {
	used[i] = true;
	path.emplace_back(i);

	for (auto next : g[i]) {
		if (used[next]) {
			continue;
		}

		dfs(path, next);
		break;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	g.resize(n);
	used.resize(n);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;

		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}

	vector<int> ans;
	dfs(ans, 0);

	reverse(begin(ans), end(ans));
	used[0] = false;
	ans.pop_back();

	dfs(ans, 0);

	cout << ans.size() << endl;
	for (int i = 0; i < (int)ans.size(); i++) {
		if (i) cout << " ";
		cout << ans[i] + 1;
	}
	cout << endl;
	return 0;
}
