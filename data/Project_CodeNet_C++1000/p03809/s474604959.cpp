#include <iostream>
#include <vector>

#define panic {std::cout << "NO\n"; return 0;}

std::vector<std::vector<int>> adjlist;
std::vector<int> a;

int64_t dfs(int node, int parent) {
	int64_t nTail = 0, maxTail = 0;
	if (adjlist[node].size() == 1) return a[node];
	for (int child : adjlist[node]) {
		if (parent != child) {
			int64_t tmp = dfs(child, node);
			nTail += tmp; maxTail = std::max(maxTail, tmp);
		}
	}

	if (nTail < a[node]) throw 0;
	int64_t t1 = a[node] * 2 - nTail;
	if (t1 < 0 ||
//		2 * maxTail - nTail > t1
		maxTail > a[node]
	) throw 0;
//	std::cerr << node+1 << " -> " << t1 << '\n';
	return t1;
}

int main() {
	int n; std::cin >> n;
	a.resize(n);
	for (int& x : a) std::cin >> x;

	if (n == 2) {
		std::cout << (a[0] == a[1] ? "YES\n" : "NO\n");
		return 0;
	}

	adjlist.assign(n, {});
	for (int i = 1; i < n; ++i) {
		int u, v;
		std::cin >> u >> v;
		--u; --v;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}

	try {
		int root = 0;
		while (adjlist[root].size() == 1) ++root; // ensure that root is not a leaf
		if (dfs(root, -1) != 0) throw 0;
		std::cout << "YES\n";
	} catch (int) {
		std::cout << "NO\n";
	}
}
