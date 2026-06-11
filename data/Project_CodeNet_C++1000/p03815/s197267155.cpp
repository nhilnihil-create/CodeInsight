#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ll x; cin >> x;
	ll quo = x / 11;
	ll mod = x % 11;
	ll ans = 2 * quo;
	if (1 <= mod && mod <= 6) ans++;
	else if (6 < mod) ans += 2;
	cout << ans << endl;
	return 0;
}