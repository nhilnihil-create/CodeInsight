#include <bits/stdc++.h>
#define ALL(v) v.begin(), v.end()
#define ALLG(v) v.begin(), v.end() ,greater<int>()
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
ll GCD(ll x, ll y) { return y ? GCD(y, x % y) : x; }
ll LCM(ll x, ll y) { return x * y / GCD(x, y); }
ll GetDigit(ll num) {
	ll digit = 0;
	while (num != 0) {
		num /= 10;
		digit++;
	}
	return digit;
}

using namespace std;
int main() {

	ll a, b, c;

	cin >> a >> b >> c;

	ll ans = 0;

	if (a == 1 && b == 1 && c == 1) {
		cout << 0 << endl;
		return 0;
	}

	if (a == b && b == c && c == a) {
		cout << -1 << endl;
		return 0;
	}

	ll ah, bh, ch;

	for (int i = 0; ; i++)
	{
		
		if (a % 2 != 0 || b % 2 != 0 || c % 2 != 0) {
			break;
		}
		ah = a / 2;
		bh = b / 2;
		ch = c / 2;

		a = bh + ch;
		b = ah + ch;
		c = bh + ah;

		ans++;

	}

	cout << ans << endl;
}