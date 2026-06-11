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

const int INF = 1e9;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);	
	

	int n, m, a, b;
	cin >> n >> m >> a >> b;
	if (!(n % a) && !(m % b)) {
		cout << "No" << endl;
		return 0;
	}
	int V = (INF - 1) / (a * b - 1);
	vector<vector<int>> ans(n, vector<int> (m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i + 1) % a == 0 && (j + 1) % b == 0) {
				ans[i][j] = -(a * b - 1) * V - 1;
			} else {
				ans[i][j] = V;
			}
		}
	}
	// int hu = ((n + a - 1) / a) * a;
	// int wu = ((n + b - 1) / b) * b;
	// for (int i = 0; i < hu; i++) {
	// 	for (int j = 0; j < wu; j++) {
	// 		if (i < n && j < m) continue;
	// 		int toi = min(i, n - 1);
	// 		int toj = min(j, m - 1);
	// 		int val = V;
	// 		if ((i + 1) % a == 0 && (j + 1) % b == 0) val *= -1;
	// 		if (ans[toi][toj] > 0 && val > 0) ans[toi][toj] += val;
	// 	}
	// }
	cout << "Yes\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
}