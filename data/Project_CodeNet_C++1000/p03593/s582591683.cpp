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

const int ALP = 26;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int c4 = 0;
	int c2 = 0;
	int c1 = 0;
	if (n % 2 && m % 2) {
		c4 = (n / 2) * (m / 2);
		c2 = (n + m - 2) / 2;
		c1 = 1;
	} else if (!(n % 2) && !(m % 2)) {
		c4 = (n / 2) * (m / 2);
	} else if (n % 2) {
		c4 = (n / 2) * (m / 2);
		c2 = m / 2;
	} else {
		c4 = (n / 2) * (m / 2);
		c2 = n / 2;
	}
	vector<int> cnt(ALP);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			cnt[c - 'a']++;
		}
	}
	for (int i = 0; i < ALP; i++) {
		int t = min(cnt[i] / 4, c4);
		cnt[i] -= 4 * t;
		c4 -= t;
	}
	for (int i = 0; i < ALP; i++) {
		int t = min(cnt[i] / 2, c2);
		cnt[i] -= 2 * t;
		c2 -= t;
	}
	for (int i = 0; i < ALP; i++) {
		int t = min(cnt[i], c1);
		cnt[i] -= t;
		c1 -= t;
	}
	if (c1 || c2 || c4) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
	}

}