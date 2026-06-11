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

#define int long long

struct Fenwick {
	int n;
	vector<int> f;

	Fenwick(int n_) {
		n = n_;
		f.resize(n);
	}

	int get(int x) {
		int res = 0;
		for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
			res += f[i];
		}
		return res;
	}

	void add(int x, int v) {
		for (int i = x; i < n; i = (i | (i + 1))) {
			f[i] += v;
		}
	}
};

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &t : a) {
		cin >> t;
	}
	vector<int> ps(n + 1);
	for (int i = 0; i < n; i++) {
		ps[i + 1] = ps[i] + a[i];
	}
	vector<int> v(n + 1);
	for (int i = 0; i <= n; i++) {
		v[i] = k * i - ps[i];
		v[i] *= -1;
	}
	{
		vector<int> seen = v;
		sort(seen.begin(), seen.end());
		seen.resize(unique(seen.begin(), seen.end()) - seen.begin());
		for (auto &t : v) {
			t = lower_bound(seen.begin(), seen.end(), t) - seen.begin();
		}
	}
	int ans = 0;
	Fenwick f(n + 1);
	for (int i = 0; i <= n; i++) {
		ans += f.get(v[i]);
		f.add(v[i], 1);
	}
	cout << ans << endl;
}
