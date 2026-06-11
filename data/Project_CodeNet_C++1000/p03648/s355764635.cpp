#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <bitset>
#include <numeric>
#include <complex>
#include <cassert>
#include <random>
using namespace std;
using ll = long long;


int main() {
	ll k; cin >> k;
	constexpr int n = 50;
	vector<ll> a(n);
	iota(a.begin(), a.end(), 0);
	for (int i = 0; i < n; i++) {
		a[i] += k / n + (n - i <= k%n);
	}
	cout << n << endl;
	for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
	return 0;
}
