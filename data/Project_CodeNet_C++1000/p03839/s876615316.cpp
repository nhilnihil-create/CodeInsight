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


int relu(int x) {
	if (x < 0)return 0;
	return x;
}

void proc() {
	LOAD(int, N);
	LOAD(int, K);
	LOADVEC(int, a, N);

	std::vector<int> tot(N + 1);
	std::vector<int> totPos(N + 1);
	tot[0] = 0;
	totPos[0] = 0;
	for (int i = 0; i < N; ++i) {
		tot[i + 1] = tot[i] + a[i];
		totPos[i + 1] = totPos[i] + relu(a[i]);
	}
	int maxScore = -1000000000000000;
	for (int k = 0; k < N - K + 1; ++k) {
		int score = 0;
		score += totPos[k];
		score += totPos[N] - totPos[k + K];
		score += relu(tot[k + K] - tot[k]);
		if (maxScore < score) {
			maxScore = score;
		}
	}
	cout << maxScore;
}

#endif
