#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <functional>
using namespace std;

typedef long long ll;

ll a[100003], ma[100003], prof[100003];

int main() {
	int n; ll t; cin >> n >> t;
	t -= t % 2;
	for (int i = 0; i < n; ++i) cin >> a[i];
	ma[n - 1] = a[n - 1];
	for (int i = n - 2; i >= 0; --i) ma[i] = max(a[i], ma[i + 1]);
	ll m = 0;
	for (int i = 0; i < n - 1; ++i) {
		prof[i] = ma[i] * t / 2 - a[i] * t / 2;
		m = max(m, prof[i]);
	}
	int ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		ans += prof[i] == m;
	}
	cout << ans << endl;

	return 0;
}