#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,n) for(ll i = 0; i < n; i++){ cout << (x[i]) << " ";} cout<<endl;

ll n, at[200008];
string s;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n;
	rep(i, 0, n){
		ll buf;
		cin >> buf;
		at[buf] = i+1;
	}
	
	set<ll, greater<ll>> l;
	set<ll> r;
	l.insert(0);
	l.insert(n+1);
	r.insert(0);
	r.insert(n+1);
	
	
	ll ans = 0;
	rep(i, 1, n+1){
		ans += (at[i]-*(l.upper_bound(at[i])))*(*(r.upper_bound(at[i]))-at[i])*i;
		l.insert(at[i]);
		r.insert(at[i]);
	}
	
	print(ans)
	return 0;
}