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

const int MOD = 1e9 + 7;

int solve(vector<int> a) {
	int n = (int)a.size();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		// for (int j = i + 1; j < n; j++) {
		// 	ans += a[j] - a[i];
		// }
		ans += i * a[i];
		ans -= (n - 1 - i) * a[i];
	}
	return ans % MOD;
} 

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	

	int n, m;
	cin >> n >> m;
	vector<int> f(n);
	for (auto &t : f) {
		cin >> t;
	}
	vector<int> s(m);
	for (auto &t : s) {
		cin >> t;
	}
	int ans = solve(f) * solve(s);
	cout << ans % MOD << endl;
}