#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N = 1e5 + 5;

vector<int> g[N];
i64 val[N];

int n, root;

void dfs(int u, int far = -1) {
	i64 sum(0), mx(0);
	for (auto v: g[u]) if (v != far) {
		dfs(v, u);
		mx = max(mx, val[v]);
		sum+= val[v]; }

	if (g[u].size() == 1)
		return;

	i64 up, down;
	down = sum - val[u];
	up = val[u] - down;

	if (down > sum - mx) throw 0;
	if (up < 0 || down < 0 || val[u] < up || val[u] < down || sum != 2 * down + up) throw 0;
	val[u] = up; }

int main() {
#ifdef HOME
	freopen("agc6c.in", "r", stdin);
	freopen("agc6c.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> val[i];

	for (int a, b, i = 1; i < n; ++i) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a); }

	if (n == 2) {
		cout << (val[1] == val[2] ? "YES" : "NO") << endl;
		return 0; }

	for (int i = 1; i <= n; ++i) if (g[i].size() > 1) {
		root = i;
		break; }

	try {
		dfs(root); }
	catch (int e) {
		cout << "NO" << endl;
		return 0; }

	cout << (!val[root] ? "YES" : "NO") << endl;

	return 0; }
