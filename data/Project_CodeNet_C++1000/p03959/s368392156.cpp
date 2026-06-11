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

typedef long long ll;

const int MOD = 1e9 + 7;
const int INF = 1e9 + 239;

int mul(int a, int b) {
	return ((ll)a * b) % MOD;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> f(n);
	vector<int> s(n);
	for (auto &t : f) {
		cin >> t;
	}
	for (auto &t : s) {
		cin >> t;
	}
	vector<int> l(n, 1);
	vector<int> r(n, INF);
	{
		int c = 0;
		for (int i = 0; i < n; i++) {
			if (c < f[i]) {
				l[i] = f[i];
				r[i] = f[i];
				c = f[i];
			} else {
				r[i] = c;
			}
		}
	}
	{
		int c = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (c < s[i]) {
				l[i] = max(l[i], s[i]);
				r[i] = min(r[i], s[i]);
				c = s[i];
			} else {
				r[i] = min(r[i], c);
			}
		}
	}
	int ans = 1;
	for (int i = 0; i < n; i++) {
		if (l[i] > r[i]) {
			cout << 0 << endl;
			return 0;
		}
		ans = mul(ans, r[i] - l[i] + 1);
	}
	cout << ans << endl;
}