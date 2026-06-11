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
	int s = 0;
	for (auto &t : a) {
		cin >> t;
		s += t;
	}	
	int one = (n * (n + 1)) / 2;
	if (s % one) {
		cout << "NO\n";
		return 0;
	}
	int cnt = s / one;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		int dt = (a[(i + 1) % n] - a[i] - cnt);
		// cerr << dt << endl;
		if (dt > 0) {
			cout << "NO\n";
			return 0;
		}
		if (dt % n) {
			cout << "NO\n";
			return 0;
		}
		v[(i + 1) % n] += abs(dt) / n;
	}
	int sv = 0;
	for (auto t : v) {
		sv += t;
	}
	if (sv != cnt) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
}