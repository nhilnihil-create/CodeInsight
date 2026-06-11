#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m; scanf("%d %d", &n, &m);
	vector<vector<int>> graph(n);
	for (int i = 0; i < m; ++i) {
		int a, b; scanf("%d %d", &a, &b);
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int> onPath(n, false);
	onPath[0] = true;
	deque<int> path{0};
	while (true) {
		bool covered = true;
		for (int next : graph[path.front()]) {
			if (!onPath[next]) {
				// printf("%d not cov from %d\n", next, path.front());
				covered = false;
				path.push_front(next);
				onPath[next] = true;
				break;
			}
		}
		if (covered) break;
	}
	while (true) {
		bool covered = true;
		for (int next : graph[path.back()]) {
			if (!onPath[next]) {
				covered = false;
				path.push_back(next);
				onPath[next] = true;
				break;
			}
		}
		if (covered) break;
	}
	printf("%lu\n", path.size());
	for (int x : path) printf("%d ", x + 1);
	printf("\n");
	return 0;
}