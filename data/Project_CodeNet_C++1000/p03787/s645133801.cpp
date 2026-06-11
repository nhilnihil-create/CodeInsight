#include <bits/stdc++.h>
#define maxn 301000
using namespace std;

int fa[maxn], du[maxn];
int fst[maxn], co[maxn];
int n, m, e;
long long a, b, c;
struct str { int v, nex; } edge[maxn << 1];

bool dfs(int u) {
	for (int i = fst[u]; i; i = edge[i].nex) {
		int v = edge[i].v;
		if (co[v] == co[u]) return false;
		if (co[v]) continue;
		if (!co[v]) { co[v] = 3 - co[u]; if (!dfs(v)) return false; }
	}
	return true;
}

int find(int a) { return (fa[a] == a) ? a : (fa[a] = find(fa[a])); }

void make_edge(int a, int b) {
	edge[++e].nex = fst[a]; fst[a] = e; edge[e].v = b;
	edge[++e].nex = fst[b]; fst[b] = e; edge[e].v = a;
}

int main() {
	scanf("%d %d",&n,&m);
	
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d",&a,&b);
		make_edge(a, b);
		du[a]++; du[b]++;
		find(a); find(b);
		if (fa[a] == fa[b]) continue;
		fa[fa[a]] = fa[b];
	}	

	for (int i = 1; i <= n; i++) {
		find(i);
		if (co[fa[i]]) continue;
		if (!du[i]) { c++; continue; }
		co[fa[i]] = 1;
		if (dfs(fa[i])) a++;
		else b++;
	}

	cout << c * (n - c) * 2LL + c * c + a * a * 2LL + a * b * 2LL + b * b << endl;
	
	return 0;
}