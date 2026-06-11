#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	ll ans = 0;
	if (n == 1) {
		ans += a[0] / 2;
		cout << ans << endl;
		return 0;
	}
	rep(i, n - 1) {
		ll tmp = a[i] + a[i + 1];
		ans += tmp / 2;
		if (tmp % 2 == 0) {
			a[i + 1] = 0;
		}
		else {
			a[i + 1] = (a[i + 1] ? 1 : 0);
		}
	}
	cout << ans << endl;
	return 0;
}
