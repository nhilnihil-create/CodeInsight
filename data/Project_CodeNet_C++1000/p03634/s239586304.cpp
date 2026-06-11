#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<vector<pair<int, int>>> Tree(N);
	for (int i = 0; i < N - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		Tree[a - 1].push_back({ b - 1,c });
		Tree[b - 1].push_back({ a - 1,c });
	}
	int Q, K;
	cin >> Q >> K;
	vector<long long> D(N, -1);
	queue<pair<int, long long>> Queue;
	Queue.push({ K - 1,0 });
	int nowdist = 0;
	while (!Queue.empty()) {
		auto p = Queue.front();
		Queue.pop();
		D[p.first] = p.second;
		for (const auto& e : Tree[p.first]) if (D[e.first] < 0) Queue.push({ e.first, p.second + e.second });
	}
	vector<long long> ans(Q);
	for (int i = 0; i < Q; i++) {
		int x, y;
		cin >> x >> y;
		ans[i] = D[x - 1] + D[y - 1];
	}
	for (long long a : ans) cout << a << endl;
}
