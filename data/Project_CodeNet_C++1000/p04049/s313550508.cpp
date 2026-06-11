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
	vector<vector<int>>edge(N);
	for (int i = 1; i < N; i++) {
		cin >> L >> R;
		L--;
		R--;
		edge[L].push_back(R);
		edge[R].push_back(L);
	}
	if (K & 1) {
		int ans = MOD;
		for (int i = 0; i < N; i++) {
			for (auto j : edge[i]) {
				vector<int>v(N, MOD);
				vector<int>w(N, MOD);
				Calculate_Depth(edge, v, i);
				Calculate_Depth(edge, w, j);
				auto depth = v;
				for (int k = 0; k < N; k++)depth[k] = min(depth[k], w[k]);
				int box = 0;
				for (auto j : depth)box += j > K / 2;
				ans = min(ans, box);
			}
		}
		cout << ans << endl;
	}
	else {
		int ans = MOD;
		for (int i = 0; i < N; i++) {
			vector<int>depth(N, MOD);
			Calculate_Depth(edge, depth, i);
			int box = 0;
			for (auto j : depth)box += j > K / 2;
			ans = min(ans, box);
		}
		cout << ans << endl;
	}
	return 0;
};