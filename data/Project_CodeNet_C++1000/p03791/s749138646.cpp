#include<map>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#define REP(i,x,y) for(ll i=x;i<=y;i++)
typedef long long ll;
using namespace std;
ll const MOD = 1000000007;
ll const MAX = 100005;
ll x[MAX];

ll mod_m(ll x, ll y) {
	return x * y%MOD;
}

ll f(ll n) {
	if (n == 0) {
		return 1;
	}
	else {
		return f(n - 1)*n%MOD;
	}
}

int main() {
	ll n;
	cin >> n;
	REP(i, 1, n) {
		cin >> x[i];
	}
	ll ans = 1;
	ll removed = 0;
	REP(i, 1, n) {
		ll t = i * 2;
		ll mech = upper_bound(x + 1, x + n + 1, t) - x - 1 - removed;

		if (mech > i) {
			removed++;
			ans = mod_m(ans,mech);
		}

	}
	ans = mod_m(ans,f(n - removed));
	cout << ans << endl;

}