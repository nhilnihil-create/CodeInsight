#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
#define REP(i, n) for(int i=1;i<=n;i++)
typedef long long ll;

int main() {
	ll q, h, s, d, n;
	cin >> q >> h >> s >> d >> n;
	ll m = min({4 * q, 2 * h, s});
	ll t = min(2 * m, d);
	ll ans;
	if (n % 2 == 0) {
		ans = (n/2)*t;
		cout << ans << endl;
	}else{
		ans = (n/2)*t + m;
		cout << ans << endl;
	}
	return 0;
}

