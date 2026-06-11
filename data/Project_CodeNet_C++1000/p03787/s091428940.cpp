#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int N = 1e5 + 5;

vector<int> g[N];
int siz[N];
bool f[N], col[N];

i64 mono, ant, col1, col2; 
int n, m;

bool dfs(int u, int far = -1) {
	bool flag = false;

	siz[u] = 1;
	f[u] = true;

	for (auto v: g[u]) if (v != far) {
		if (!f[v]) {
			col[v] = !col[u];
			flag|= dfs(v, u);
			siz[u]+= siz[v]; }
		else
			flag|= col[u] == col[v]; }

	return flag; }

int main() {
#ifdef HOME
	freopen("agc11c.in", "r", stdin);
	freopen("agc11c.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n >> m;
	for (int a, b, i = 0; i < m; ++i) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a); }

	for (int i = 1; i <= n; ++i) if (!f[i]) {
		if (dfs(i))
			++col1;
		else
			++col2;
		if (siz[i] == 1) {
			++mono;
			--col2; } }

	ant+= mono * mono;
	ant+= mono * (n - mono) * 2;
	ant+= col1 * col1;
	ant+= col1 * col2 * 2;
	ant+= col2 * col2 * 2;

	cout << ant << endl;

	return 0; }
