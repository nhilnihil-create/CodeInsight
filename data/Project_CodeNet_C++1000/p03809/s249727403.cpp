#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

#define fi first
#define se second

typedef long long ll;
typedef double ff;
typedef std::pair<int, int> pii;

const int kN = 1e5 + 5;

int a[kN], dg[kN], fa[kN]; ll f[kN]; std::vector <int> E[kN];

void Dfs(int cur) {
	if(dg[cur] == 1) return;
	ll s = 0, mx = 0;
	for(auto x : E[cur])
		if(x != fa[cur]) {
			fa[x] = cur; Dfs(x); s += f[x];
			mx = std::max(mx, f[x]);
		}
	f[cur] = 2 * a[cur] - s;
	if(f[cur] < 0 || f[cur] > a[cur] || mx > a[cur]) {
		printf("NO"); exit(0);
	}
}

int main() {
	int n; rd(n);
	for(int i = 1; i <= n; ++i) rd(a[i]);
	if(n == 2) { printf(a[1] == a[2] ? "YES" : "NO"); return 0; }
	for(int i = 1; i < n; ++i) {
		int u, v; rd(u, v);
		E[v].push_back(u);
		E[u].push_back(v);
		++dg[u]; ++dg[v];
	}
	int rt;
	for(int i = 1; i <= n; ++i) {
		if(dg[i] != 1) rt = i;
		else f[i] = a[i];
	}
	Dfs(rt);
	printf(!f[rt] ? "YES" : "NO");
	return 0;
}