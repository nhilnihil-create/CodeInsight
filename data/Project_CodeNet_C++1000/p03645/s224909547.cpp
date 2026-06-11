#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	bool ans = false;
	cin >> N >> M;
	vector<vector<int>> E(N + 1);
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		E[a].push_back(b);
		E[b].push_back(a);
	}
	for (int L : E.at(1)) {
        for (int i = 0; i < E[L].size(); i++) {
            if (E[L][i] == N) {
                ans = true;
            }
        }
    }
	cout << (ans ? "POSSIBLE" : "IMPOSSIBLE") << endl;
	return 0;
}