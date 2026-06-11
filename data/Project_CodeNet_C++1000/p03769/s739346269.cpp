#include <bits/stdc++.h>

typedef long long LL;

std::vector<int> p; int tot;
void solve(LL n) {
	if (!n) return;
	if (n & 1) solve(n >> 1), p.push_back(++tot);
	else solve(n - 1), p.insert(p.begin(), ++tot);
}
int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	LL n; std::cin >> n, solve(n);
	std::cout << (p.size() << 1) << '\n';
	for (int i : p) std::cout << i << ' ';
	for (int i = 1; i <= tot; ++i) std::cout << i << ' ';
	std::cout << '\n';
	return 0;
}