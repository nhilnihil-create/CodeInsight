#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<vector<int>> E;

int N, K;
int d[2000];

void dfs(int pos, int parent) {
	for (int i = 0; i < E[pos].size(); i++) {
		int nxt = E[pos][i];
		if (nxt == parent)continue;

		d[nxt] = d[pos] + 1;
		dfs(nxt, pos);
	}
}

int main() {
	cin >> N >> K;
	E.resize(N);
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		E[a].push_back(b);
		E[b].push_back(a);
	}

	int ans = 1145141919;

	for (int i = 0; i < N; i++) {
		if (K % 2 == 0) {
			int cnt = 0;
			d[i] = 0;
			dfs(i, -1);
			for (int j = 0; j < N; j++)if (d[j] > K / 2)cnt++;
			ans = min(ans, cnt);
		}
		else {
			for (int j = 0; j < E[i].size(); j++) {
				int cnt = 0;
				d[i] = 0;
				d[E[i][j]] = 0;
				dfs(i, E[i][j]);
				dfs(E[i][j], i);
				for (int k = 0; k < N; k++) {
					if (d[k] > (K - 1) / 2)cnt++;
				}
				ans = min(ans, cnt);
			}
		}
	}
	cout << ans << endl;
	return 0;
}