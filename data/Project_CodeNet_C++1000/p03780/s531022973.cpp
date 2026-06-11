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

const int N = 5005;

bitset<N> pdp[N];
bitset<N> sdp[N];
int ps[N][N + 1];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (auto &t : a) {
		cin >> t;
	}
	pdp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		pdp[i + 1] = pdp[i] | (pdp[i] << a[i]);
	}
	sdp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		sdp[i + 1] = sdp[i] | (sdp[i] << a[n - 1 - i]);
	}	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < N; j++) {
			ps[i][j + 1] = ps[i][j] + sdp[i][j];
		}
	}	
	int c = n;
	for (int i = 0; i < n; i++) {
		int fu = 0;
		for (int p = 0; p < k; p++) {
			if (!pdp[i][p]) continue;
			int l = max(0, k - p - a[i]);
			int r = k - p;
			int any = (ps[n - 1 - i][r] > ps[n - 1 - i][l]);
			fu |= any;
		}
		c -= fu;
	}
	cout << c << endl;
}
