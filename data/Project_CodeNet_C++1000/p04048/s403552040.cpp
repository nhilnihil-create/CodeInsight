#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, x;

ll f(ll a, ll b) {
	if (a == b)
		return a;
	if (a > b)
		swap(a, b);
	ll r = b / a - (b % a == 0);
	return r * 2 * a + f(a, b - r * a);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> x;
	cout << n + f(n - x, x);
}
