#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll ans1 = 0;
	// 奇数 正  偶数 負
	vector<ll> accum1(n + 1, 0);
	for (ll i = 1; i <= n; i++) {
		accum1[i] += accum1[i - 1];
		accum1[i] += a[i - 1];
		if (i % 2 != 0) {
			if (0 < accum1[i]) {
			}
			else if (accum1[i] <= 0) {
				ans1 += abs(accum1[i]) + 1;
				accum1[i] += abs(accum1[i]) + 1;
			}			
		}
		else { // i % 2 == 0
			if (0 <= accum1[i]) {
				ans1 += abs(accum1[i]) + 1;
				accum1[i] -= abs(accum1[i]) + 1;
			}
			else if (accum1[i] < 0) {				
			}
		}
	}
	// 奇数 負  偶数 正
	ll ans2 = 0;
	vector<ll> accum2(n + 1, 0);
	for (ll i = 1; i <= n; i++) {
		accum2[i] += accum2[i - 1];
		accum2[i] += a[i - 1];
		if (i % 2 == 0) {
			if (0 < accum2[i]) {
			}
			else if (accum2[i] <= 0) {
				ans2 += abs(accum2[i]) + 1;
				accum2[i] += abs(accum2[i]) + 1;
			}
		}
		else { // i % 2 != 0
			if (0 <= accum2[i]) {
				ans2 += abs(accum2[i]) + 1;
				accum2[i] -= abs(accum2[i]) + 1;
			}
			else if (accum2[i] < 0) {
			}		
		}
	}
	cout << min(ans1, ans2) << endl;
	return 0;
}