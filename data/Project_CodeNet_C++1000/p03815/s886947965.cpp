#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
	ll x;
	cin >> x;
	
	ll ans = x / 11 * 2;
	x %= 11;
	if (x > 6) ans +=2 ;
	else if (x > 0) ans += 1;
	cout << ans;
	return 0;
}


