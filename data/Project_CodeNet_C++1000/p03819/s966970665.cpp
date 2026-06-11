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

const int N = 2e5 + 7;

namespace Fenw {
	int f[N];

	void add(int x, int val) {
		for (int i = x; i < N; i = (i | i + 1)) {
			f[i] += val;
		}
	}

	int sum(int x) {
		int ans = 0;
		for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
			ans += f[i];
		}
		return ans;
	}

	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
}

int ans[N];
vector<int> br[N];
vector<int> dv[N];

void init() {
	for (int i = 2; i < N; i++) {
		for (int j = i; j < N; j += i) {
			dv[j].push_back(i);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	init();
	cerr << "init ok" << endl;

	int n, M;
	cin >> n >> M;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		br[r].push_back(l);
	}
	fill(ans, ans + N, n);
	for (int i = 1; i + 1 < N; i++) {
		for (auto l : br[i]) {
			Fenw::add(l, 1);
		}
		for (auto x : dv[i + 1]) {
			//[i + 2 - x, i]
			ans[x] -= Fenw::sum(i + 2 - x, i);
		}
	}
	for (int i = 1; i <= M; i++) {
		cout << ans[i] << '\n';
	}
}
