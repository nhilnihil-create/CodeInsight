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

ll n, m, x[100008], mod[100008], p[100008];
string s;

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n >> m;
	rep(i, 0, n-1){
		cin >> x[i];
	}
	sort(x, x+n);
	
	memset(mod, 0, sizeof(mod));
	memset(p, 0, sizeof(p));
	ll buf = -1;
	rep(i, 0, n-1){
		mod[x[i]%m]++;
		if(x[i] == buf){
			p[x[i]%m]++;
			buf = -1;
		}
		else{
			buf = x[i];
		}
	}
	
	ll ans = 0;
	ans += mod[0]/2;
	rep(i, 1, ((m-1)/2)){
		if(mod[i] < mod[m-i]){
			ans += mod[i];
			ans += min(p[m-i], (mod[m-i]-mod[i])/2);
		}
		else{
			ans += mod[m-i];
			ans += min(p[i], (mod[i]-mod[m-i])/2);
		}
	}
	if(m%2 == 0){
		ans += mod[m/2]/2;
	}
	
	print(ans)
	return 0;
}