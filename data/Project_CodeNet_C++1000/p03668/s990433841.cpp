#include <bits/stdc++.h>
using namespace std;

vector<int> edge[100010];

int dfs(int from, int par) {
	int ret = 0;
	for(int to : edge[from]) {
		if(to == par) continue;
		ret ^= dfs(to, from) + 1;
	}
	return ret;
}

int main() {
	int n; cin >> n;
	for(int i = 0; i < n - 1; ++i) {
		int x, y; cin >> x >> y;
		--x, --y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	if(dfs(0, -1) == 0) {
		cout << "Bob" << '\n';
	} else {
		cout << "Alice" << '\n';
	}
	return 0;
}
