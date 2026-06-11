#include <iostream>
using namespace std;
#define ll long long

ll x[100009], y[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	ll s = 0, ts = 0;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 0; i < m; i++)
		cin >> y[i];
	for (int i = 0; i < n; i++) {
		s = (s + 1LL * x[i] * i - ts + 1000000007LL * 5) % 1000000007LL;
		ts = (ts + x[i]) % 1000000007LL;
	}
	ll ans = s; s = ts = 0;
	for (int i = 0; i < m; i++) {
		s = (s + 1LL * y[i] * i - ts + 1000000007LL * 5) % 1000000007LL;
		ts = (ts + y[i]) % 1000000007LL;
	}
	ans = (ans * s) % 1000000007LL;
	cout << ans << '\n';
	return 0;
}