#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>

using namespace std;

int N;
vector<vector<int>> E;

int grundy[100000 + 100];

int dfs(int pos, int bef) {
	if (grundy[pos] != -1)return grundy[pos];

	int g = 0;
	for (int i = 0; i < E[pos].size(); i++) {
		int nxt = E[pos][i];
		if (nxt == bef)continue;
		g ^= (dfs(nxt, pos) + 1);
	}
	return grundy[pos] = g;
}

int main() {

	cin >> N;
	E.resize(N);
	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		E[u].push_back(v), E[v].push_back(u);
	}

	for (int i = 0; i < N; i++)grundy[i] = -1;
	dfs(0, -1);

	if (grundy[0])cout << "Alice" << endl;
	else cout << "Bob" << endl;
	return 0;
}