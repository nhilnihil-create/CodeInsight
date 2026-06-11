#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main()
{
	int N;
	cin >> N;
	vector<int> x(N), a(N * N, -1);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	for (int i = 0; i < N; i++) {
		cin >> x[i]; --x[i];
		a[x[i]] = i;
		for (int j = 0; j < N - 1; j++) {
			if (j < i) {
				pq.emplace(x[i] - 1, i);
			}
			else {
				pq.emplace(N * N + x[i] - 1, i);
			}
		}
	}
	bool ng = false;
	for (int i = 0; i < N * N; i++) if (a[i] == -1) {
		auto p = pq.top(); pq.pop();
		if (p.first < i) {
			ng = true;
			break;
		}
		a[i] = p.second;
	}
	if (ng) {
		cout << "No" << endl;
		return 0;
	}
	vector<vector<int>> pos(N);
	for (int i = 0; i < N * N; i++) {
		pos[a[i]].push_back(i);
	}
	for (int i = 0; i < N; i++) {
		if (pos[i][i] != x[i]) {
			ng = true;
			break;
		}
	}
	if (ng) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	for (int i = 0; i < N * N; i++) {
		printf("%d%c", a[i] + 1, " \n"[i + 1 == N * N]);
	}
	return 0;
}
