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

	int n, m, k;
	cin >> n >> m >> k;
	for (int f = 0; f <= n; f++) {
		for (int s = 0; s <= m; s++) {
			if (f * m + s * n - 2 * f * s == k) {
				cout << "Yes\n";
				return 0;
			}
		}
	}
	cout << "No\n";
}