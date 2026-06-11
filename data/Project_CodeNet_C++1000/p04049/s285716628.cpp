#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> adj;
std::vector<std::pair<int, int>> edges;

int min(int a, int b) {
	return a < b ? a : b;
}

int bfs(int center, int k) {
	std::queue<std::pair<int, int>> q;
	bool visited[2000] = { false };
	int maxDist, numClose;
	if (k % 2 == 0) {
		maxDist = k / 2;
		q.push(std::pair<int, int>(center, 0));
		visited[center] = true;
		numClose = 1;
	} else {
		maxDist = (k - 1) / 2;
		q.push(std::pair<int, int>(edges[center].first, 0));
		q.push(std::pair<int, int>(edges[center].second, 0));
		visited[edges[center].first] = true;
		visited[edges[center].second] = true;
		numClose = 2;
	}
	while (!q.empty()) {
		int cur = q.front().first;
		int dist = q.front().second;
		q.pop();
		if (dist < maxDist) {
			for (int i : adj[cur]) {
				if (!visited[i]) {
					visited[i] = true;
					q.push(std::pair<int, int>(i, dist + 1));
					++numClose;
				}
			}
		}
	}
	return numClose;
}

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	int n, k;
	std::cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		adj.push_back(std::vector<int>());
	}

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges.push_back(std::pair<int, int>(u, v));
	}

	int res = (int) 2e9;
	for (int i = 0; i < n - 1; ++i) {
		res = min(res, n - bfs(i, k));
	}
	if (k % 2 == 0) {
		res = min(res, n - bfs(n - 1, k));
	}
	
	std::cout << res << '\n';
	return 0;
}