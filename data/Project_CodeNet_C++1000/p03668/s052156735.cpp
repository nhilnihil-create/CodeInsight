#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;

int N;
vector<vi> E;
vi G;

void dfs(int cur, int pre) {
	for (int i = 0; i < (int)E[cur].size(); ++i) {
		if (E[cur][i] != pre) {
			dfs(E[cur][i], cur);
			G[cur] ^= (G[E[cur][i]] + 1);
		}
	}
}

int main(void) {
	cin >> N;

	E.resize(N + 1);
	for (int i = 1; i < N; ++i) {
		int x, y;
		cin >> x >> y;
		E[x].push_back(y);
		E[y].push_back(x);
	}

	G.resize(N + 1, 0);
	dfs(1, 0);

	if (G[1] == 0)
		cout << "Bob\n";
	else
		cout << "Alice\n";
	return 0;
}
