#include <bits/stdc++.h>

const int MAXN = 100010;
typedef long long LL;
LL pre[MAXN];
int n, m, A[MAXN];
void add(int l, int r, int v, int d) {
	if (l > r) return ;
	pre[l] += v; pre[l + 1] -= v; v += (r - l) * d;
	pre[r + 1] -= v; pre[r + 2] += v;
	pre[l + 1] += d; pre[r + 1] -= d;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> m >> n;
	for (int i = 1; i <= m; ++i) std::cin >> A[i];
	for (int i = 1; i < m; ++i) {
		int t = A[i + 1] - A[i];
		if (A[i] <= A[i + 1]) {
			add(A[i] + 1, A[i + 1], t, -1);
			add(1, A[i], t, 0);
			add(A[i + 1] + 1, n, t, 0);
		} else {
			t += n;
			add(A[i + 1] + 1, A[i], t, 0);
			add(A[i] + 1, n, t, -1);
			add(1, A[i + 1], t - (n - A[i]), -1);
		}
	}
	LL ans = std::numeric_limits<LL>::max();
	for (int i = 1; i <= n; ++i) pre[i] += pre[i - 1];
	for (int i = 1; i <= n; ++i) pre[i] += pre[i - 1];
	for (int i = 1; i <= n; ++i) ans = std::min(ans, pre[i]);
	std::cout << ans << std::endl;
	return 0;
}
