#include <cstdio>
#include <algorithm>

int N, K, g, mx;

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 1, x; i <= N; ++i)
		scanf("%d", &x),
		g = std::__gcd(g, x),
		mx = std::max(mx, x);
	puts(K <= mx && K % g == 0 ? "POSSIBLE" : "IMPOSSIBLE");
	return 0;
}