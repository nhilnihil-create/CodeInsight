#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using pii = pair<int, int>;

//const ll INF = 1e18L + 5;
//const int INF = 1e9 + 5;
//const double pi = 3.14159265358979323846;

int		main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	
	ll ans = 0;
	int x = a, y = b, z = c; 
	while (true) {
		if (x & 1 || y & 1 || z & 1) {
			cout << ans << endl;
			return 0;
		} else if (x == y && x == z) {
			cout << -1 << endl;
			return 0;
		}
		ans++;
		x = b / 2 + c / 2;
		y = a / 2 + c / 2;
		z = a / 2 + b / 2;
		a = x, b = y, c = z;
	}
}