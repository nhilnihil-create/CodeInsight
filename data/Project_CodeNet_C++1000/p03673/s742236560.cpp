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


int main() {
	ll n;
	cin >> n;
	vector<ll> ans;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	for(ll i=1; i<=n; i+=2){
		ans.push_back(a[i-1]);
	}
	reverse(all(ans));
	for(ll i=2; i<=n; i+=2){
		ans.push_back(a[i-1]);
	}
	if(n%2 == 0) reverse(all(ans));
	for(auto x : ans) cout << x << " ";
	cout << endl;
	return 0;
}
