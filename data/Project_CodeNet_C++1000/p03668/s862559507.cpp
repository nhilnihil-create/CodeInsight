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

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 1e-8;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<vector<int>>edge(N + 1);
	for (int i = 1; i < N; i++) {
		cin >> L >> R;
		edge[L].push_back(R);
		edge[R].push_back(L);
	}
	vector<int>dis(N + 1, MOD);
	vector<int>parent(N + 1);
	dis[1] = 0;
	queue<int>Q;
	Q.push(1);
	while (!Q.empty()) {
		int cn = Q.front();
		Q.pop();
		for (auto i : edge[cn]) {
			if (dis[i] > dis[cn] + 1) {
				dis[i] = dis[cn] + 1;
				Q.push(i);
				parent[i] = cn;
			}
		}
	}
	vector<int>used(N + 1);
	vector<int>nim(N + 1);
	for (int i = 2; i <= N; i++) {
		if (edge[i].size() == 1)Q.push(i);
	}
	edge[1].clear();
	while (!Q.empty()) {
		int cn = Q.front();
		Q.pop();
		if (cn == 1)continue;
		int node = cn;
		int nx;
		while (1) {
			nx = parent[node];
			used[node]++;
			used[nx]++;
			node = nx;
			if (edge[nx].size() != 2) {
				break;
			}
		}
		nim[node] ^= (dis[cn] - dis[node]+nim[cn]);
		//nim[node] ^= nim[cn];
		if (edge[node].size() - used[node] == 1)Q.push(node);
	}
	if (!nim[1])cout << "Bob\n";
	else cout << "Alice\n";
	return 0;
}