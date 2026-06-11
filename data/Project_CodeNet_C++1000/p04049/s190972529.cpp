#include <bits/stdc++.h>
using namespace std;
//#define cerr if (false) cerr
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto _x : v) cerr << _x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int _i = 0; _i < (n); ++_i) cerr << a[_i] << ", "; cerr << endl
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& x) {
	return os << "(" << x.first << "," << x.second << ")";
}
typedef long long ll;
typedef long double ld;
bitset<2005> reach[2005];
vector<int> E[2005];
int mxh;
void dfs(int x, int root, int p = -1, int h = 0) {
	if (h > mxh) return;
	reach[root][x] = 1;
	for (int y : E[x]) {
		if (y == p) continue;
		dfs(y, root, x, h + 1);
	}
}
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	vector<pair<int, int>> edges;
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		E[a].push_back(b);
		E[b].push_back(a);
		edges.emplace_back(a, b);
	}
	mxh = k / 2;
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		dfs(i, i);
		if (k % 2 == 0) ans = max(ans, (int)reach[i].count());
	}
	if (k % 2) {
		for (auto& e : edges) {
			auto tot = reach[e.first] | reach[e.second];
			ans = max(ans, (int)tot.count());
		}
	}
	printf("%d\n", n - ans);
}
