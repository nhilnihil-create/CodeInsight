#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    const ll mod = 1000000007;
    ll n; cin >> n;
    ll ans = 1;
	for (ll i = 1; i <= n; i++) {
		ans *= i;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}