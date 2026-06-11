#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1000000007;
signed main() {
	int n, ok = 0, ans = 1; cin >> n; string s, t; cin >> s >> t;
	for (int h = 0; h < n; h++) {
		if (s[h] == t[h]) {
			if (ok == 0) { ans *= 3; } if (ok == 1) { ans *= 2; } ok = 1;
		}
		else {
			if (ok == 0) { ans *= 6; } if (ok == 1) { ans *= 2; } if (ok == 2) { ans *= 3; } ok = 2; h++;
		} ans %= mod;
	} cout << ans % mod << endl; return 0;
}