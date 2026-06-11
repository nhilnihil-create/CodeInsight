#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;

void Calculate_Depth(vector<vector<int>>&edge, vector<int>&depth, int stnode) {
	depth[stnode] = 0;
	queue<int>Q;
	Q.push(stnode);
	while (!Q.empty()) {
		int cn = Q.front();
		Q.pop();
		for (auto i : edge[cn]) {
			if (depth[i] > depth[cn] + 1) {
				depth[i] = depth[cn] + 1;
				Q.push(i);
			}
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	vector<int>p(N);
	for (auto &i : p) {
		cin >> i;
		i--;
	}
	int ans = 0;
	if (p[0]) {
		p[0] = 0;
		ans++;
	}
	vector<vector<int>>edge(N);
	for (int i = 1; i < N; i++) {
		edge[i].push_back(p[i]);
		edge[p[i]].push_back(i);
	}
	vector<int>depth(N, MOD);
	Calculate_Depth(edge, depth, 0);
	priority_queue<pair<int, int>>PQ;
	for (int i = 0; i < N; i++) {
		PQ.push({ depth[i],i });
	}
	vector<int>deep(N);
	while (!PQ.empty()) {
		auto cn = PQ.top().second;
		auto c = PQ.top().first;
		PQ.pop();
		deep[cn] = max(deep[cn], depth[cn]);
		if (deep[cn] <= K)continue;
		if (deep[cn] - depth[cn] + 1 == K) {
			ans++;
			deep[cn] = 1;
		}
		for (auto i : edge[cn]) {
			if (depth[i] > depth[cn])continue;
			deep[i] = max(deep[i], deep[cn]);
		}
	}
	cout << ans << endl;
	return 0;
}