#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll; 
typedef long double ld;
typedef pair<ll, ll> pll;

const ll N = 2e5 + 30, Mod = 1e9 + 7;
const ll SQ = 330;

ll a[N];
int main () {
    ios::sync_with_stdio(0), cin.tie(0);
    ll n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
    	cin >> a[i];
    ll ans = 0;
  
	ll po = 1;
	while (po <= n && !a[po]) po ++;
	if (po > n) {
		return cout << ans, 0;
	}
	while (po <= n) {
		ll j = po;
		ll res = 0;
		while (j <= n && a[j]) {
			res += a[j];
			j ++;
		}
		ans += res / 2;
		if (po == j) po ++;
		else po = j;
	}
	cout << ans;
    return (0);
}