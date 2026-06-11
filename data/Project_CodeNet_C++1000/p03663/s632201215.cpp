#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
using ll = long long;
using ii = pair<int, int>;

inline bool query(ll x) {
	cout << "? " << x << endl;
	char c; cin >> c; return c == 'Y';
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	ll b = 1;
	while (b < 1e9 && query(10*b)) b *= 10;

	if (b == 1e9) {
		while (b > 1 && query(b - 1)) b /= 10;
	}

	ll l = b, h = 10*b - 1;
	while (l <= h) {
		ll m = (l + h) >> 1;
		query(10*m) ? h = m-1 : l = m+1;
	}
	cout << "! " << l << endl;
}