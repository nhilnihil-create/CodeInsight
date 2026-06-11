#include <bits/stdc++.h>

#define rep(i, x, n) for (int i = x; i < n; i++)
typedef long long ll;

const int INF = 1e9 + 7;

using namespace std;

int main()
{
	cin.tie(0); ios::sync_with_stdio(false);

	ll n, a, b;
	cin >> n >> a >> b;

	vector<ll> x(n);
	rep (i, 0, n)
		cin >> x[i];

	ll res = 0;
	rep (i, 0, n - 1) {
		ll tmp = x[i + 1] - x[i];
		if (tmp * a < b) {
			res += tmp * a;
		} else {
			res += b;
		}
	}

	cout << res << endl;
	return 0;
}
