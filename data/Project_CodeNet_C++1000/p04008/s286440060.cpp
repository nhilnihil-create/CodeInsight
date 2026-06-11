#include<bits/stdc++.h>
const int maxn = 100100;
int dep[maxn], h[maxn], nxt[maxn];
int n, k, a[maxn];
int ans;
inline void link(int f,int x) { nxt[x] = h[f], h[f] = x; }
inline void dfs(int x) {
	for(int i = h[x];i;i = nxt[i])
		dfs(i), dep[x] = std::max(dep[x], dep[i] + 1);
	if(x != 1 && dep[x] >= k - (a[x] != 1)) ++ ans, dep[x] = -1;
}
int main() {
	std::ios::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> k;
	for(int i = 1;i <= n;++i) std::cin >> a[i];
	for(int i = 2;i <= n;++i) link(a[i], i);
	dfs(1);
	std::cout << ans + (a[1] != 1) << '\n';
}
