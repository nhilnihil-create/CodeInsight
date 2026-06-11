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

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<int> cnt(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		cnt[u] ^= 1;
		cnt[v] ^= 1;
	}
	int ok = 1;
	for (auto t : cnt) {
		ok &= (!t);
	}
	if (ok) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}