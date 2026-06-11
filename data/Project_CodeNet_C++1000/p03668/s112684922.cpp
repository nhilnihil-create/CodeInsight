#include <bits/stdc++.h>

using namespace std;

const int N = 101000;

vector <int> adj[N];
int val[N];

// if fix 1, we have a green hackenbush

int dfs(int u, int l) {
	val[u] = 0;
	for (int x: adj[u]) {
		if (x == l) continue;
		val[u]^=(dfs(x, u)+1);
	}
	return val[u];
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n-1; ++i) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	dfs(1, -1);
	if(val[1] == 0) {
		printf("Bob\n");
	} else {
		printf("Alice\n");
	}

}