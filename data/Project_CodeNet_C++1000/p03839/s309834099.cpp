#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll n, k, a[100008], aa[100008], ra[100008], b[100008];
string s;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n >> k;
	rep(i, 1, n){cin >> a[i];}
	aa[0] = 0;
	rep(i, 1, n){aa[i] = aa[i-1]+max(a[i], 0LL);}
	ra[n+1] = 0;
	rrep(i, n, 1){ra[i] = ra[i+1]+max(a[i], 0LL);}
	b[0] = 0;
	rep(i, 1, n){b[i] = b[i-1]+a[i];}
	
	ll ans = 0;
	rep(i, 0, n-k){
		ll tmp = aa[i]+max(b[i+k]-b[i], 0LL)+ra[i+k+1];
		ans = max(tmp, ans);
	}
	
	print(ans)
	return 0;
}