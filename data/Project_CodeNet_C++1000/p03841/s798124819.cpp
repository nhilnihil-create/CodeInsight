#include <bits/stdc++.h>

typedef std::pair<int, int> pi;
std::priority_queue<pi, std::vector<pi>, std::greater<pi> > q;
const int MAXN = 510 * 510;
int n, A[MAXN], B[MAXN];
std::vector<pi> add[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1, t; i <= n; ++i) {
		std::cin >> t; B[i] = t;
		for (int j = 1; j < i; ++j) add[1].emplace_back(t - 1, i);
		add[t].emplace_back(t, i);
		for (int j = i + 1; j <= n; ++j) add[t + 1].emplace_back(n * n, i);
	}
	for (int i = 1; i <= n * n; ++i) {
		for (auto t : add[i]) q.push(t);
		if (q.empty() || q.top().first < i)
			return std::cout << "No" << std::endl, 0;
		A[i] = q.top().second; q.pop();
	}
	std::cout << "Yes" << std::endl;
	for (int i = 1; i <= n * n; ++i)
		std::cout << A[i] << (" \n" [i == n * n]);
	return 0;
}
