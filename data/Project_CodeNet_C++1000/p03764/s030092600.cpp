#include <bits/stdc++.h>
using namespace std;

template<typename T>
void out(T x) { cout << x << endl; exit(0); }
#define watch(x) cout << (#x) << " is " << (x) << endl




typedef long long ll;
const ll mod = 1e9+7;
const int maxn = 1e6 + 5;





ll solve(vector<ll> v) {
    int n = v.size();
    ll res = 0;
    for (ll i=0; i<n; i++) {
	res += i*v[i]%mod;
	res %= mod;
	res -= 1ll*(n-i-1)*v[i]%mod;
	res %= mod;
    }

    return res;
}


int n, m;
vector<ll> r, c;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin>>n>>m;
    for (int i=0; i<n; i++) {
	ll x; cin>>x;
	r.push_back(x);
    }
    for (int i=0; i<m; i++) {
	ll x; cin>>x;
	c.push_back(x);
    }

    sort(r.begin(), r.end());
    sort(c.begin(), c.end());

    ll ans = solve(r)*solve(c)%mod;

    ans += mod;
    ans %= mod;
    out(ans);  

    return 0;
}
