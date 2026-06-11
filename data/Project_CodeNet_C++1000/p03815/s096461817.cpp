#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll x;
	cin >> x;

	ll ans = 0;
	ll a = x / 11;
	ans += 2 * a;
	if (x % 11 > 6) ans += 2;
	else if (x % 11 == 0) ans += 0;
	else ans++;

	dunk(ans);

	return 0;
}