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

	int h, w;
	cin >> h >> w;
	int ch = h + 1;
	int cw = w + 1;
	vector<pair<int, int>> e;
	for (int i = 0; i < h + w; i++) {
		int x;
		cin >> x;
		e.push_back({x, i < h});
	}
	int ans = 0;
	sort(e.begin(), e.end());
	for (int i = 0; i < h + w; i++) {
		if (e[i].second == 0) {
			ans += e[i].first * ch;
			cw--;
		} else {
			ans += e[i].first * cw;
			ch--;
		}
	}
	cout << ans << endl;
}