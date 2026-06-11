#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define zep(i,m,n) for(ll i = (m); i < (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	ll n, x;
	cin >> n >> x;

	ll ans = n;
	ll a = max(x, n-x);
	ll b = min(x, n-x);
	while(b > 0){
		ans += 2*b*(a/b);
		
		ll tmp = a;
		a = b;
		b = tmp%b;
	}
	ans -= a;
	print(ans)
	return 0;
}