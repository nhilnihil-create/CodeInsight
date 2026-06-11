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

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &t : a) {
		cin >> t;
	}
	int ans = 0;
	int f = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] <= f) {
			f = max(f, a[i] + 1);
		} else {
			ans += (a[i] - 1) / f;
			if (i == 0) f = 2;
		}
	}
	cout << ans << '\n';
}