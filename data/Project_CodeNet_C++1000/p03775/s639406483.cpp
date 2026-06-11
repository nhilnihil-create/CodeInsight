#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define MOD 1e9+7;
using namespace std;
using ll = long long;

int main() {
	ll n, nn, count, ans;
	cin >> n;
	nn = n;
	count = 1;
	while(nn >= 10) {
		nn /= 10;
		count++;
	}
	ans = count;
	for (ll i = 2 ; i * i <= n; i++) {
		if (n % i == 0) {
			ll x = n / i;
			count = 1;
			while (x >= 10) {
				x /= 10;
				count++;
			}
			ans = count;
		}
	}
	cout << ans;
	return 0;
}