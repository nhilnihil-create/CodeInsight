#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	const ll mod = 1000000007;
	ll n; cin >> n;
	string s, t; cin >> s >> t;
	ll ans = 1;
	ll i = 0;
	bool preOneFlag;
	if (s[i] == t[i]) {
		ans *= 3;
		preOneFlag = true;
		i++;
	}
	else {
		ans *= 6;
		preOneFlag = false;
		i += 2;
	}
	for ( ; i < s.size(); ) {
		if (preOneFlag) {
			if (s[i] == t[i]) {
				ans *= 2;
				preOneFlag = true;
				i++;
			}
			else {
				ans *= 2;
				preOneFlag = false;
				i += 2;
			}
		}
		else { // 上下別れている
			if (s[i] == t[i]) {
				ans *= 1;
				preOneFlag = true;
				i++;
			}
			else {
				ans *= 3;
				preOneFlag = false;
				i += 2;
			}
		}
		ans %= mod;
	}	
	cout << ans << endl;
	return 0;
}