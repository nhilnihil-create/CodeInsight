
// C - X: Yet Another Die Game

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	ll x;
	cin >> x;

	ll a = x / 11;
	int b = x % 11;

	ll ans;
	if (b == 0) ans = a * 2;
	else if (b <= 6) ans = a * 2 + 1;
	else ans = a * 2 + 2;

	cout << ans << endl;

	return 0;
}