#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> can_use(10, true);

void input(void) {
	cin >> N >> K;
	for (int i = 0; i < K; ++i) {
		int di; cin >> di;
		can_use[di] = false;
	}
}

int res = (1 << 30);

void dfs(int now, int d) {
	if (now >= N) {
		res = min(now, res);
		return;
	}
	if (d >= 6) return;
	for (int i = 0; i < 10; ++i)
		if (can_use[i])
			dfs(now * 10 + i, d + 1);
}

void solve(void) {
	dfs(0, 0);
}

int main(void) {
	input(); solve();
	cout << res << endl;
	return 0;
}