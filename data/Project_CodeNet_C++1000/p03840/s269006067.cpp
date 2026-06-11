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
	
	ll a[7];
	zep(i, 0, 7){
		cin >> a[i];
	}
	
	ll ans = 0;
	ans += 2*(a[0]/2);
	ans += a[1];
	ans += 2*(a[3]/2);
	ans += 2*(a[4]/2);

	ll ans2 = 0;
	if(a[0] > 0 && a[3] > 0 && a[4] > 0){
		ans2 += 3;
		a[0]--;
		a[3]--;
		a[4]--;
	}
	ans2 += 2*(a[0]/2);
	ans2 += a[1];
	ans2 += 2*(a[3]/2);
	ans2 += 2*(a[4]/2);
	
	print(max(ans, ans2))
	return 0;
}