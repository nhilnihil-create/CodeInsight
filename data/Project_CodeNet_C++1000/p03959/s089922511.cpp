#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define int long long
int r[114514], t[114514], a[114514];
bool b[114514];
int ans;
signed main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)cin >> t[i];
	for (int i = 0; i < n; i++)cin >> a[i];
	r[0] = t[0]; b[0] = 1;
	for (int i = 1; i < n; i++) {
		r[i] = t[i];
		if (t[i] > t[i - 1]) b[i] = 1;
	}
	for (int i = n - 1; i >= 0; i--) {
		if (i == n - 1 || a[i] > a[i + 1]) {
			if (b[i]) {
				if (a[i] != r[i]) {
					cout << "0\n";
					return 0;
				}
			}
			else {
				if (r[i] < a[i]) {
					cout << "0\n";
					return 0;
				}
				r[i] = a[i]; b[i] = 1;
			}
		}
		else r[i] = min(r[i], a[i]);
	}
	int ans = 1;
	for (int i = 0; i < n; i++) {
		if (!b[i]) {
			ans *= r[i];
			ans %= 1000000007;
		}
	}
	cout << ans << endl;
}