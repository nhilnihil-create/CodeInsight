#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

const int N = 1e5 + 7;
const int K = 11;

int c[N];
int dp[K][N];
vector<int> g[N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < K; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = -1;
		}
	}
	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		g[i].push_back(i);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int v, d;
		cin >> v >> d >> c[i];
		v--;
		dp[d][v] = i;
	}
	for (int j = K - 1; j > 0; j--) {
		for (int i = 0; i < n; i++) {
			for (auto t : g[i]) {
				dp[j - 1][t] = max(dp[j - 1][t], dp[j][i]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (dp[0][i] == -1) {
			cout << 0 << '\n';
		} else {
			cout << c[dp[0][i]] << '\n';
		}
	}
}
