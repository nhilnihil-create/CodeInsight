#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define fi first
#define se second
#define N 200005

using namespace std;
typedef pair<int,int> Pair;

inline int input() {
	int x; char ch; while (!isdigit(ch = getchar()));
	for (x = ch ^ 48; isdigit(ch = getchar()); x = x * 10 + (ch ^ 48));
	return x;
}

int n, fa[N], f[N];
vector<int> T[N];

inline bool cmp(int x, int y) { return f[x] < f[y]; }

void dfs(int u) {
	for (int v : T[u]) dfs(v);
	sort(T[u].begin(), T[u].end(), cmp);
	for (int v : T[u]) f[u] = max(f[u], f[v]) + 1;
}

int main() {

	n = input();
	for (int i = 2; i <= n; ++i)
		fa[i] = input(), T[fa[i]].push_back(i);

	dfs(1);
	printf("%d\n", f[1]);
	return 0;
}
