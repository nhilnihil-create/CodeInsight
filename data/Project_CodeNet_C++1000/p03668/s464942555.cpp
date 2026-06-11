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

int n, sg[MAXN];

struct Edge {
	int v, nxt;
}e[MAXN<<1];
int first[MAXN], eCnt;

inline void AddEdge(int u, int v) {
	e[++eCnt].v = v;
	e[eCnt].nxt = first[u];
	first[u] = eCnt;
}

void DFS(int u, int fa) {
	for (int i=first[u];i;i=e[i].nxt) {
		int v = e[i].v;
		if (v == fa) continue;
		DFS(v, u);
		sg[u] ^= (sg[v] + 1);
	}
}

void init() {
	read(n);
	for (int i=1,u,v;i<n;++i) {
		read(u); read(v);
		AddEdge(u, v);
		AddEdge(v, u);
	}
}

void solve() {
	DFS(1, 0);
	puts(sg[1]? "Alice" : "Bob");
}

int main() {
	init();
	solve();
	return 0;
}
