#include <bits/stdc++.h>

typedef long long LL;
const int N = 2000005, mod = 1000000007;
int f[N], n, qaq, ans;

void up(int &x, int y) {x += y - mod, x += x >> 31 & mod;}
void up(int &x, int y, int z) {x = (x + (LL) y * z) % mod;}
int _(int n) { return n < 0 ? 1 : f[n]; }

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	std::cin >> n, f[0] = 1, f[1] = n; int q = (LL) (n - 1) * (n - 1) % mod;
	int sum = n - 1;
	for (int i = 2; i <= n; ++i) {
		up(f[i] = f[i - 1], q);
		up(sum, mod - 1), up(sum, _(i - 3));
		up(f[i], sum);
	}
	std::cout << f[n] << '\n';
	return 0;
}