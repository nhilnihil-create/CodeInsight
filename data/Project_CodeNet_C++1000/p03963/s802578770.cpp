#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	ll n, k; cin >> n >> k;

	ll ans = 1;
	ll cnt = n;
	ans *= k;
	cnt--;
	if (cnt != 0) {
		while (cnt--) {
			ans *= k - 1;
		}
	}
	cout << ans << endl;
	return 0;
}