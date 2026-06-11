#if 1
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <set>
#include <map>
#include <numeric>
#include <cassert>

using namespace std;
#define int long long
#define uint unsigned long long
constexpr int MOD = 1000000007;
constexpr int INF = 1145141919810;

#define LOADVEC(type,name,N) std::vector<type>name(N); \
for (int nnn = 0; nnn < N; ++nnn) { \
	cin >> name[nnn]; \
}

#define LOADVEC2(type,name0,name1,N) std::vector<type>name0(N),name1(N); \
for (int nnn = 0; nnn < N; ++nnn) { \
	cin >> name0[nnn];cin >> name1[nnn]; \
}

#define LOADVEC3(type,name0,name1,name2,N) std::vector<type>name0(N),name1(N),name2(N); \
for (int nnn = 0; nnn < N; ++nnn) { \
	cin >> name0[nnn];cin >> name1[nnn];cin >> name2[nnn]; \
}

#define LOAD(type,name) type name; \
cin >> name;


void proc();

signed main() {
	ios::sync_with_stdio(false);
	proc();
	return 0;
}

/*
--------------------------------------------------------
--------------------------------------------------------
---------------    template      ----------------------
--------------------------------------------------------
--------------------------------------------------------
*/


void proc() {
	LOAD(int, N);
	LOAD(int, M);
	LOADVEC2(int, a, b, M);
	LOAD(int, Q);
	LOADVEC3(int, v, d, c, Q);
	std::vector<std::unordered_set<int>> connect(N);
	for (int i = 0; i < M; ++i) {
		connect[a[i] - 1].insert(b[i] - 1);
		connect[b[i] - 1].insert(a[i] - 1);
	}
	std::vector<std::vector<int>>dp(N);
	for (int i = 0; i < N; ++i) {
		dp[i].resize(11);
	}
	for (int i = 0; i < Q; ++i) {
		dp[v[i] - 1][d[i]] = i + 1;
	}
	for (int i = 10; i >= 1; --i) {
		for (int v = 0; v < N; ++v) {
			for (int u : connect[v]) {
				dp[u][i - 1] = std::max({ dp[u][i - 1] ,dp[v][i] });
			}
			dp[v][i - 1] = std::max({ dp[v][i - 1] ,dp[v][i] });
		}
	}
	//
	for (int v = 0; v < N; ++v) {
		if (dp[v][0] == 0) {
			cout << 0;
		}
		else {
			cout << c[dp[v][0] - 1];
		}
		cout << endl;
	}
}


#endif
