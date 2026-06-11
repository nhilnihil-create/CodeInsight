#include <bits/stdc++.h>

const int MAXN = 100010;
int n, M, ansl[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> M;
	for (int i = 1, L, R; i <= n; ++i) {
		std::cin >> L >> R; --L;
		int t1, t2, l = 1, r;
		for (; l <= L; l = r + 1) {
			t1 = L / l, t2 = R / l;
			r = std::min(L / t1, R / t2);
			if (t2 > t1) ++ansl[l], --ansl[r + 1];
		}
		++ansl[L + 1], --ansl[R + 1];
	}
	for (int i = 1; i <= M; ++i)
		std::cout << (ansl[i] += ansl[i - 1]) << '\n';
	return 0;
}
