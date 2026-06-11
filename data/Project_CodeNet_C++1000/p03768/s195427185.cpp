#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}
int main() {
	int n = ri();
	int m = ri();
	int a[m];
	int b[m];
	std::vector<int> hens[n];
	for (int i = 0; i < m; i++) a[i] = ri() - 1, b[i] = ri() - 1, hens[a[i]].push_back(b[i]), hens[b[i]].push_back(a[i]);
	int q = ri();
	int start[q];
	int dist[q];
	int color[q];
	for (int i = 0; i < q; i++) start[i] = ri() - 1, dist[i] = ri(), color[i] = ri();
	std::vector<int> res(n, -1);
	std::vector<int> cur(n, -1);
	for (int i = 10; i; i--) {
		for (int j = 0; j < q; j++) if (dist[j] == i) cur[start[j]] = std::max(cur[start[j]], j);
		std::vector<int> next(n, -1);
		for (int j = 0; j < n; j++) {
			for (auto k : hens[j]) next[k] = std::max(next[k], cur[j]);
		}
		std::swap(cur, next);
		for (int j = 0; j < n; j++) res[j] = std::max(res[j], cur[j]);
	}
	for (int i = 0; i < q; i++) res[start[i]] = std::max(res[start[i]], i);
	for (int i = 0; i < n; i++) {
		if (res[i] == -1) std::cout << 0 << std::endl;
		else std::cout << color[res[i]] << std::endl;
	}
	return 0;
}
