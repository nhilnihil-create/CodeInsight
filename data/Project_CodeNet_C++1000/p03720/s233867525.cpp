#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<int>> road(N);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		road[a-1].push_back(b);
		road[b-1].push_back(a);
	}

	for (int i = 0; i < road.size(); ++i) {
		cout << road[i].size() << endl;
	}
	return 0;
}
