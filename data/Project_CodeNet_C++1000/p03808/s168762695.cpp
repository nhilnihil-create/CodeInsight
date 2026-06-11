#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <queue>
#include <cmath>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;

int main() {
	long long int n;
	cin >> n;
	vector<long long int> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<long long int> res(n, 0);
	long long int s = accumulate(v.begin(), v.end(), (long long int)0);
	long long int base = (1 + n) * n / 2;
	if (s % base != 0) {
		cout << "NO" << endl;
		return 0;
	}
	long long int nn = s / base;
	if (nn - (v[0] - v[n - 1]) < 0 || (nn - (v[0] - v[n - 1])) % n != 0) {
		cout << "NO" << endl;
		return 0;
	}
	res[0] += (nn - (v[0] - v[n - 1])) / n;
	for (int i = 1; i < n; i++) {
		int diff = v[i] - v[i - 1];
		if (nn - diff < 0 || (nn - diff) % n != 0) {
			cout << "NO" << endl;
			return 0;
		}
		res[i] += (nn - diff) / n;
	}
	if (accumulate(res.begin(), res.end(), 0) != nn) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
	}
}




