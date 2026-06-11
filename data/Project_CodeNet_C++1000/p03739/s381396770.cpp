#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
using namespace std;
using ll = long long;
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
int main() {
	int n;
	cin >> n;
	ll a[n];
	rep(i, n) cin >> a[i];
	ll ans = 4e18;
	ll sum = 0, now = 0;
	rep(i, n) {
		if (i % 2) {
			if (sum + a[i] <= 0) {
				now += 1 - (sum + a[i]);
				sum = 1;
			} else {
				sum += a[i];
			}
		} else {
			if (sum + a[i] >= 0) {
				now += sum + a[i] + 1;
				sum = -1;
			} else {
				sum += a[i];
			}
		}
	}
	ans = min(ans, now);
	sum = 0, now = 0;
	rep(i, n) {
		if (i % 2 == 0) {
			if (sum + a[i] <= 0) {
				now += 1 - (sum + a[i]);
				sum = 1;
			} else {
				sum += a[i];
			}
		} else {
			if (sum + a[i] >= 0) {
				now += sum + a[i] + 1;
				sum = -1;
			} else {
				sum += a[i];
			}
		}
	}
	ans = min(ans, now);
	cout << ans << endl;
	return 0;
}