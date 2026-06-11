#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

const int MAXN = 100005;
int f[MAXN], n;
vector<int> gra[MAXN];

void dfs(int u, int fa) {
	for (int v : gra[u]) if (v != fa) {
		dfs(v, u);
		f[u] ^= f[v];
	}
	if (u > 1) ++f[u];
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		gra[u].push_back(v), gra[v].push_back(u);
	}
	dfs(1, 0);
	puts(f[1] ? "Alice" : "Bob");
	return 0;
}