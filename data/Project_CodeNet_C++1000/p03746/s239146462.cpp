#include <bits/stdc++.h>
typedef long long ll; 
 
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> g(N + 1);
	deque<int> res;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
		
		if (i == 0) {
			res.push_front(a);
			res.push_back(b);
		}
	}

	vector<bool> passed(N + 1, false);
	passed[res.front()] = true;
	passed[res.back()] = true;
	int cnt = 0;
	while (cnt++ < N) {
		bool ok = true;
		int s = res.front();
		int t = res.back();

		for (int i = 0; i < g[s].size(); ++i) {
			if (!passed[g[s][i]]) {
				passed[g[s][i]] = true;
				res.push_front(g[s][i]);
				ok = false;
				break;
			}
		}
		for (int i = 0; i < g[t].size(); ++i) {
			if (!passed[g[t][i]]) {
				passed[g[t][i]] = true;
				res.push_back(g[t][i]);
				ok = false;
				break;
			}
		}

		if (ok) {
			cout << res.size() << endl;
			while (!res.empty()) {
				cout << res.front() << " ";
				res.pop_front();
			}
			cout << endl;
			break;
		}
	}

	return 0;
}
