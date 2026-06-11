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
	int n; cin >> n;
	ll a[200005];
	vector<ll> b;
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n){
		if(i%2==0) b.pb(a[i]);
		else b.insert(b.begin(), a[i]);
	}
	if(n%2==1) reverse(b.begin(), b.end());
	rep(i, 0, n-1) cout << b[i] << ' ';
	cout << b[n-1] << endl;
	return 0;
}