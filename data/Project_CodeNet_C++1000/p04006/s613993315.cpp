#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 1<<20, mod = 924844033;
ll n, a[maxn], x;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> x;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) a[i+n] = a[i];
	ll ans = 1ll<<60;
	for(int d = 0; d < n; d++) {
		ll tans = x*d;
		multiset<ll> u;
		for(int i = 1; i <= 2*n; i++) {
			u.insert(a[i]);
			if(i-d-1 > 0) u.erase(u.find(a[i-d-1]));
			if(i > n) {
				tans += *u.begin();
			}
		}
		ans = min(ans, tans);
	}
	cout << ans;
}
