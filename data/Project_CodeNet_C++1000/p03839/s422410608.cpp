#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cmath>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;

int main() {
	int n, k;
	cin >> n >> k;
	vector<long long int> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<long long int> v1(n, 0), v2(n, 0);
	v1[0] = max(v[0], (long long int)0);
	v2[n - 1] = max(v[n - 1], (long long int)0);
	vector<long long int> v3(n, 0);
	v3[0] = v[0];
	for (int i = 1; i < n; i++) {
		v1[i] = v1[i - 1] + max(v[i], (long long int)0);
		v2[n - i - 1] = v2[n - i] + max(v[n - i - 1], (long long int)0);
		v3[i] = v[i] + v3[i - 1];
	}
	long long int res = 0;
	for (int i = 0; i + k <= n; i++) {
		// [i, i + k - 1]
		long long int r = 0;
		if (i - 1 >= 0) {
			r += v1[i - 1];
		}
		if (i + k < n) {
			r += v2[i + k];
		}
		r += max((long long int)0, v3[i + k - 1] - (i > 0 ? v3[i - 1] : 0));
		res = max(res, r);
	}
	cout << res << endl;
}




