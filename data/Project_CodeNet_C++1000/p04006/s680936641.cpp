#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){ cout << (x[i]) << " ";} cout<<endl;

ll n, x, c[2019][2019];
string s;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n >> x;
	rep(j, 1, n){
		cin >> c[0][j];
	}
	c[0][0] = c[0][n];
	
	rep(i, 1, n-1){
		rep(j, 1, n){
			c[i][j] = min(c[i-1][j-1], c[i-1][j]);
		}
		c[i][0] = c[i][n];
	}
	
	ll sm[2019];
	memset(sm, 0, sizeof(sm));
	rep(i, 0, n-1){
		rep(j, 1, n){
			sm[i] += c[i][j];
		}
	}
	
	ll ans = sm[0];
	rep(i, 1, n-1){
		ans = min(sm[i]+i*x, ans);
	}
	
	print(ans)
	return 0;
}