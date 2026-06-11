#include <bits/stdc++.h>

const int MAXN = 100010;
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
void addedge(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}
int dfs(int u, int fa = 0) {
	int tc = 0;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa)
			tc ^= dfs(to[i], u) + 1;
	return tc;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	int n; std::cin >> n;
	for (int i = 1, t1, t2; i < n; ++i)
		std::cin >> t1 >> t2, addedge(t1, t2);
	std::cout << (dfs(1) ? "Alice" : "Bob") << std::endl;
	return 0;
}
