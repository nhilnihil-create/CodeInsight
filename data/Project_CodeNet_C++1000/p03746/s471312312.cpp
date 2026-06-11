#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	int m = ri();
	std::vector<int> hen[n];
	for (int i = 0; i < m; i++) {
		int a = ri() - 1;
		int b = ri() - 1;
		hen[a].push_back(b);
		hen[b].push_back(a);
	}
	
	std::vector<bool> used(n);
	auto extend = [&] (int start) {
		std::vector<int> path{start};
		int cur = start;
		used[cur] = true;
		while (1) {
			if (!hen[cur].size()) break;
			int next = hen[cur].back();
			hen[cur].pop_back();
			if (used[next]) continue;
			path.push_back(next);
			cur = next;
			used[next] = true;
		}
		return path;
	};
	auto r0 = extend(0);
	auto r1 = extend(0);
	std::reverse(r1.begin(), r1.end());
	r1.pop_back();
	r0.insert(r0.begin(), r1.begin(), r1.end());
	printf("%d\n", (int) r0.size());
	for (auto i : r0) printf("%d ", i + 1);
	puts("");
	return 0;
}
