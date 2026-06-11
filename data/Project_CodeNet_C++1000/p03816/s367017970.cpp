#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll n; cin >> n;
	const ll p = 100001;
	vector<ll> num(p, 0);
	for (ll i = 0; i < n; i++) {
		ll a;  cin >> a;
		num[a]++;
	}
	ll evenCnt = 0;
	ll oddCnt = 0;
	for (ll i = 1; i < p; i++) {
		if (0 < num[i]) {
			if (num[i] % 2 == 0) evenCnt++;
			else oddCnt++;
		}
	}
	ll ans = 0;
	ll quo= evenCnt / 2;
	ll mod = evenCnt % 2;	
	ans += quo * 2;
	if (mod == 1) {
		ans += 1;
		oddCnt -= 1;
	}
	ans += oddCnt;
	cout << ans << endl;
	return 0;
}