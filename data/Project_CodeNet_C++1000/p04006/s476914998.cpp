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

ll a[2001];
ll b[2001];
int main() {
	ll n, x; cin >> n >> x;
	rep(i, 0, n) {
		cin >> a[i];
		b[i] = a[i];
	}

	ll ans = INF;
	rep(k, 0, n) {
		ll can = k * x;
		rep(i, 0, n)b[i] = min(b[i], a[(i - k + n) % n]);
		rep(i, 0, n)can += b[i];
		ans = min(ans, can);
	}
	cout << ans << endl;
	return 0;
}