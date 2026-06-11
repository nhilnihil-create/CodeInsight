#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	int a[n];
	for (int i = 0; i < n; i++) a[i] = ri();
	int l = ri(), q = ri();
	int upper[n];
	for (int i = 0; i < n; i++) upper[i] = std::upper_bound(a, a + n, a[i] + l) - a - 1;
	std::vector<int> go[n];
	for (int i = n - 1; i >= 0; i--) {
		if (upper[i] == i) continue;
		int cur = upper[i];
		go[i].push_back(cur);
		for (int j = 0; ; j++) {
			if (j >= (int) go[cur].size() || cur == go[cur][j]) break;
			go[i].push_back(cur = go[cur][j]);
		}
	}
	for (int i = 0; i < q; i++) {
		int x = ri() - 1, y = ri() - 1;
		if (x > y) std::swap(x, y);
		int cost = 0;
		for (int i = 20; i >= 0; i--)
			if (i < (int) go[x].size() && go[x][i] < y) cost += 1 << i, x = go[x][i];
		std::cout << cost + 1 << std::endl;
	}
	return 0;
}
