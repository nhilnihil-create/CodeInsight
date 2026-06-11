#include<bits/stdc++.h>
using namespace std;
#define ll long
ll MOD = 1e9 + 7;
ll a[100005];
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n;
	cin >> n;

	ll flag = 1;
	ll ans = 1;

	if (n % 2 == 0) {

		for (ll i = 0; i < n; i++) {
			ll x;
			cin >> x;
			a[x]++;

			if (x >= n || x % 2 == 0 || a[x] > 2) {
				flag = 0;
				cout << "0" << endl;
				break;
			}


			if (a[x] == 1)
				ans = ans * 2 % MOD;
		}
	}

	else {

		for (ll i = 0; i < n; i++) {
			ll x;
			cin >> x;
			a[x]++;
			if (x >= n || x % 2 == 1 || a[0] > 1 || a[x] > 2) {
				flag = 0;
				cout << "0" << endl;
				break;
			}


			if (x != 0 && a[x] == 1)
				ans = ans * 2 % MOD;
		}
	}

	if (flag)
		cout << ans << endl;
	return 0;
}