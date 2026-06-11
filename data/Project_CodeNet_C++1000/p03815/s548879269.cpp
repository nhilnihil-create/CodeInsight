#pragma GCC optimize "trapv"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll x;
	cin >> x;
	if (x <= 6) return cout << 1 << '\n', 0;
	ll ans = x/11;
	ans *= 2;
	x %= 11;
	cout << ans + (x + 6 - 1) / 6 << '\n';
	return 0;
}
