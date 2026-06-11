#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;
int main() {
	ll n, ans = 1;
	cin >> n;
	for (int i=1; i<=n; i++) {
		ans*=i;
		if (ans >= MOD)
			ans %= MOD;
	}
	cout << ans << '\n';
	return 0;
}
