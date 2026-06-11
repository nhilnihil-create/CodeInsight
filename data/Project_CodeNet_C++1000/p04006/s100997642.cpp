#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 1e18;
const int N = 2010;

ll n, x, a[N], b[N][N];

void calc() {
	for (ll i = 0; i < n; i++)
		b[i][0] = a[i];
	for (ll i = 1; i < n; i++)
		for (ll j = 0; j < n; j++) {
			ll prev = (j - i + n) % n;
			b[j][i] = min(b[j][i - 1], a[prev]);
		}
}

ll get(ll shifts) {
	ll res = x * shifts;
	for (ll i = 0; i < n; i++)
		res += b[i][shifts];
	return res;
}

int main() {
	cin >> n >> x;
	for (ll i = 0; i < n; i++) 
		cin >> a[i];
	calc();
	ll ans = INF;
	for (ll i = 0; i < n; i++)
		ans = min(ans, get(i));
	cout << ans;
}
