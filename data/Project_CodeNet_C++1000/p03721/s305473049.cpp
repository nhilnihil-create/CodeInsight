#include <bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define pb push_back
#define fi first
#define se second

using ll = long long;
using G = vector<vector<int>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;

ll GCD(ll x, ll y){
	return y ? GCD(y, x%y) : x;	
}

int main() {
	ll n, k; cin >> n >> k;
	map<ll, ll> m;
	rep(i, 0, n){
		ll a, b; cin >> a >> b;
		m[a] += b;
	}
	ll cnt = 0;
	ll ans = 0;
	for(auto kv: m){
		cnt += kv.se;
		if(cnt>=k){
			ans = kv.fi;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}