#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define rg register
using namespace std;
typedef long long LL;
const int MAXN = 100005;
const int INF = 0x3f3f3f3f;

template <typename T> inline void read(T &AKNOI) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	AKNOI = flag * x;
}

template <typename T> inline void cmin(T &x, T y) {
	if (x > y) x = y;
}

template <typename T> inline void cmax(T &x, T y) {
	if (x < y) x = y;
}

int n, K, fa[MAXN];
int dep[MAXN], mxd[MAXN], dp[MAXN];

struct Edge {
	int v, nxt;
}e[MAXN];
int first[MAXN], eCnt;

inline void AddEdge(int u, int v) {
	e[++eCnt].v = v;
	e[eCnt].nxt = first[u];
	first[u] = eCnt;
}

void DFS(int u) {
	mxd[u] = dep[u];
	for (int i=first[u];i;i=e[i].nxt) {
		int v = e[i].v;
		dep[v] = dep[u] + 1;
		DFS(v);
		if (dp[v]) continue;
		cmax(mxd[u], mxd[v]);		
	}
	if (fa[u] != 1 && mxd[u] - dep[u] + 1 >= K) dp[u] = 1;
}

void init() {
	read(n); read(K);
	for (int i=1;i<=n;++i) {
		read(fa[i]);
		if (i > 1) AddEdge(fa[i], i);
	}
}

void solve() {
	if (fa[1] != 1) {
		dp[1] = 1;
		fa[1] = 1;
	}
	DFS(1);
	int ans = 0;
	for (int i=1;i<=n;++i) {
		ans += dp[i];
	}
	printf("%d\n", ans);
}

int main() {
	init();
	solve();
	return 0;
}
