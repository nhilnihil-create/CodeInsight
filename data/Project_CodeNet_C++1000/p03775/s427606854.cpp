#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//  2進数ならば baseNumber を  2 とする
// 10進数ならば baseNumber を 10 とする
ll GetDigitsCount(ll targetNumber, ll baseNumber=10) {
	ll digitsCount = 0;
	while (targetNumber != 0) {
		digitsCount++;
		targetNumber /= baseNumber;
	}
	return digitsCount;
}

int main() {

	ll n; cin >> n;
	ll ans = 9223372036854775807LL;
	for (ll i = 1; i * i <= n ; i++) {
		if (n % i != 0) continue;
		ll i_digit = GetDigitsCount(i);
		ll j_digit = GetDigitsCount(n / i);
		ans = min(ans, max(i_digit, j_digit));
	}
	cout << ans << endl;
	return 0;
}