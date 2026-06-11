#include <bits/stdc++.h>

const int N = 100005;

int head[N], nxt[N], f[N], ans, n, k;
void link(int x, int y) { nxt[y] = head[x], head[x] = y; }

int dfs(int x) {
	int max = 1;
	for (int i = head[x]; i; i = nxt[i])
		max = std::max(max, dfs(i) + 1);
	if (max == k) ++ans, max = 0;
	return max;
}
int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i) std::cin >> f[i];
	ans = f[1] != 1;
	for (int i = 2; i <= n; ++i) link(f[i], i);
	for (int i = head[1]; i; i = nxt[i]) for (int j = head[i]; j; j = nxt[j]) dfs(j);
	std::cout << ans << '\n';
	return 0;
}