#include <bits/stdc++.h>
#define N 100005

using namespace std;

int n;
int fa[N], deg[N], f[N];
int head[N], nex[N], to[N], te;

vector <int> val[N];

inline void cmax(int &u, int v) { if(u < v) u = v; }
inline void read(int &x) {
	x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
}
inline void ade(int u, int v) {
	nex[++te] = head[u], head[u] = te;
	to[te] = v;
}

void dfs(int u) {
	for(int i = head[u]; i; i = nex[i]) {
		int v = to[i];
		dfs(v);
		val[u].push_back(f[v]);
	}
	sort(val[u].begin(), val[u].end());
	for(int i = deg[u] - 1; ~i; --i)
		cmax(f[u], val[u][i] + deg[u] - i);
	return;
}

int main() {
	read(n);
	for(int i = 2; i <= n; ++i) {
		read(fa[i]), ade(fa[i], i);
		++deg[fa[i]];
	}
	dfs(1);
	cout << f[1] << endl;
	return 0;
}