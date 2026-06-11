#include<bits/stdc++.h>
// Begin Header {{{
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i,n) for(ll i=0; i<n; i++)
#define loop(i, j, n) for(ll i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF  = 0x3f3f3f3f;
const long long mod=1e9+7;
const long double PI = acos(-1);
template <class T>void UNIQUE(vector<T> &x){
	sort(all(x));
	x.erase(unique(all(x)), x.end());
}

// }}} End Header
inline ll kaijo(ll n){
	ll ans = 1;
	for(ll i=1; i<=n; i++){
		ans*=i;
		ans%=mod;
	}
	return ans;
}

int main() {
	ll n, m, ans = 0;
	cin >> n >> m;
	if(abs(n-m)>1){
		cout << 0 << endl;
		return 0;
	}
	ans = kaijo(n)*kaijo(m);
	if(n == m) ans*=2;
	cout << ans%mod << endl;
	return 0;
}
