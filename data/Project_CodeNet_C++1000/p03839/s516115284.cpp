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

const int N = 1e5 + 7;

int ps[N];
int ps2[N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	
		
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &t : a) {
		cin >> t;
	}
	for (int i = 0; i < n; i++) {
		ps[i + 1] = ps[i] + a[i];
	}
	for (int i = 0; i < n; i++) {
		ps2[i + 1] = ps2[i] + max((int)0, a[i]);
	}
	int v = ps2[n];
	int ans = 0;
	for (int i = 0; i + k <= n; i++) {
		int cv = v - (ps2[i + k] - ps2[i]);
		ans = max(ans, cv);
		// cerr << cv << ' ' << ps[i + k] - ps[i] << endl;
		ans = max(ans, cv + (ps[i + k] - ps[i]));
	}
	cout << ans << endl;
}