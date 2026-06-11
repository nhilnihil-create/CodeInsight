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

const int INF = 1e18 + 239;
const int N = 4005;

int n;
int a[N];
int mn[N][N];

void init() {
	for (int i = 0; i < n; i++) {
		mn[1][i] = a[i];
	}
	for (int i = 1; i + 1 <= n; i++) {
		for (int j = 0; j + i + 1 <= n; j++) {
			mn[i + 1][j] = min(a[j], mn[i][j + 1]);
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	

	int x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		a[i + n] = a[i];
	}
	n *= 2;
	init();
	int ans = INF;
	for (int k = 0; k < n / 2; k++) {
		int c = k * x;
		for (int i = 0; i < n / 2; i++) {
			c += mn[k + 1][i];
		}
		ans = min(ans, c);
	}
	cout << ans << endl;
}