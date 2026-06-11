#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> G[100000];
int color[100000];
int group[100000];

void dfs(int v, int c, int g, bool& b) {
	if(color[v] != -1) {
		if(color[v] != c) {
			b = false;
		}
		return;
	};
	color[v] = c;
	group[v] = g;
	for(auto u : G[v]) {

		dfs(u, 1 - c, g, b);
	}
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N, M;
	cin >> N >> M;

	for(int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	if(N == 1) {
		cout << 1 << endl;
		return  0;
	}

	memset(color, -1, sizeof color);
	int g = 0;
	ll p = 0, q = 0, one = 0;
	for(int i = 0; i < N; i++) {
		if(G[i].size() == 0) {
			one++;
		}
		else if(color[i] == -1) {
			bool b = true;
			dfs(i, 0, g, b);
			if(b) q++;
			else p++;
			g++;
		}
	}

	cout << one * one + 2 * one * (N - one) + p * p + 2 * p * q + 2 * q * q << endl;
}