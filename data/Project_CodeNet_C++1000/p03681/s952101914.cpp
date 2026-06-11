#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	long long int res = 0;
	const int mod = 1e9 + 7;
	if (abs(n - m) >= 2) {
		cout << 0 << endl;
		return 0;
	}
	vector<long long int> v(1, 1);
	for (int i = 1; i <= max(n, m); i++) {
		v.push_back(v.back() * i % mod);
	}
	res = v[m] * v[n] % mod;
	if (m == n) res = res * 2 % mod;
	cout << res << endl;
}
