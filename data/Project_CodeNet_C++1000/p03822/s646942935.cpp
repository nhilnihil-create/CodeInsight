#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define rg register
using namespace std;
typedef long long LL;
const int MAXN = 100005;

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

int n, dp[MAXN];
int son[MAXN], cnt;

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
	for (int i=first[u];i;i=e[i].nxt) {
		DFS(e[i].v);
	}
	cnt = 0;
	for (int i=first[u];i;i=e[i].nxt) {
		son[++cnt] = dp[e[i].v];
	}
	sort(son+1, son+cnt+1);
	for (int i=1;i<=cnt;++i) {
		cmax(dp[u], son[i] + cnt-i+1);
	}
}

void init() {
	read(n);
	for (int i=2,fa;i<=n;++i) {
		read(fa);
		AddEdge(fa, i);
	}
}

void solve() {
	DFS(1);
	printf("%d\n", dp[1]);
}

int main() {
	init();
	solve();
	return 0;
}
