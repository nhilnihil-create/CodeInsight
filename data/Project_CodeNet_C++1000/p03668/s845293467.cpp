#include <bits/stdc++.h>
using namespace std;

namespace fastIO {
	template<typename T> inline void read(T &x) {
		register char c = getchar();
		register bool flag = 0;
		while (!isdigit(c)) {
			flag |= c == '-';
			c = getchar();
		}
		x = c - '0';
		c = getchar();
		while (isdigit(c)) {
			x = x * 10 + c - '0';
			c = getchar();
		}
		if (flag) {
			x = -x;
		}
	}
}
using namespace fastIO;

int n;
vector<int> adj[100010];

int dfs(int x, int pre) {
	int adjx_size = adj[x].size(), ret = 0;
	for (int i = 0; i < adjx_size; ++i) {
		int y = adj[x][i];
		if (y != pre) {
			ret ^= dfs(y, x) + 1;
		}
	}
	return ret;
}

int main() {
	read(n);
	for (int i = 1; i < n; ++i) {
		int x, y;
		read(x), read(y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	puts(dfs(1, 0) ? "Alice" : "Bob");
}