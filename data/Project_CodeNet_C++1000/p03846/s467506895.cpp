#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1000000007;

int main()
{
	ll n; cin >> n;
	
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];
	
	vector<ll> num(n, 0);
	for (ll i = 0; i < n; i++) num[a[i]]++;
	
	bool can = true;
	
	if (n % 2 == 0) {

		for (ll i = 0; i < n; i++) {

			if (i == 0) {
				if (num[i] == 0) continue;
				else {
					can = false;
					break;
				}
			}
			else { // 1 <= i
				if (i % 2 == 1) {
					if (num[i] == 2) continue;
					else {
						can = false;
						break;
					}
				}
				else {
					if (num[i] == 0) continue;
					else {
						can = false;
						break;
					}
				}
			}
		}

	}
	else { // n % 2 == 1

		for (ll i = 0; i < n; i++) {
		
			if (i == 0) {
				if (num[i] == 1) continue;
				else {
					can = false;
					break;
				}
			}
			else{
				if (i % 2 == 1) {
					if (num[i] == 0) continue;
					else {
						can = false;
						break;
					}
				}
				else {
					if (num[i] == 2) continue;
					else {
						can = false;
						break;
					}
				}
			}
		}

	}

	ll ans = 1;
	for (ll i = 1; i <= n / 2; i++) {
		ans *= 2LL;
		ans %= mod;
	}

	if (can) cout << ans << endl;
	else cout << 0 << endl;
	
	return 0;
}