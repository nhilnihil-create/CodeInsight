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

ll n, k, a[100008], b[100008];
string s;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n >> k;
	rep(i, 1, n){
		cin >> a[i] >> b[i];
	}
	
	ll ans = 0;
	if(k == 0){
		rep(i, 1, n){
			if(a[i] == 0){
				ans += b[i];
			}
		}
	}
	else{
		rep(bit, 0, 30){
			ll buf = 0;
			if(k >= (1 << bit)){
				ll kk = (bit == 0)? k : (k - (1 << bit)) | ((1 << bit)-1);
				rep(i, 1, n){
					if((kk | a[i]) == kk){
						buf += b[i];
					}
				}
				ans = max(buf, ans);
			}
		}
	}
	print(ans)
	return 0;
}