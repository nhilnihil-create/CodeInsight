#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
#include <bitset>
#include <cmath>
#include <set>
#include <queue>

typedef long long ll;
#define rep(i,s,n)for(ll i = s;i<n;i++)
#define repe(i,s,n)for(ll i = s;i<=n;i++)
#define rep_r(i,s,n)for(ll i = n;i>s;i--)
#define rep_re(i,s,n)for(ll i = n;i>=s;i--)
using namespace std;
static const ll MOD = 1e9 + 7;
static const ll INF = 1e25;
static const ll MAX_N = 100001;

ll a[200001];
ll p[200001];
set<ll> s;
int main() {
	ll n; cin >> n;
	rep(i, 0, n) {
		cin >> a[i];
		p[a[i] - 1] = i;
	}
	ll ans = 0;
	s.insert(-1);
	s.insert(n);

	rep(i, 0, n) {
		set<ll>::iterator it = s.lower_bound(p[i]);
		ll r = *it - p[i];
		it--;
		ll l = p[i] - *it;
		ans += a[p[i]] * l*r;
		s.insert(p[i]);
	}
	cout << ans << endl;

	return 0;
}