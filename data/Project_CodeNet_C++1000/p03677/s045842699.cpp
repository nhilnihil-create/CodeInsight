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
	
	ll n, m;
	cin >> n >> m;
	ll a[n], g[2*m], cnt[2*m];
	zep(i, 0, n){cin >> a[i]; a[i]--;}
	
	ll up = 0;
	memset(g, 0, sizeof(g));
	memset(cnt, 0, sizeof(cnt));
	zep(i, 1, n){
		ll tmp = (a[i]+m-a[i-1])%m;
		up += tmp;
		g[a[i]+m] += tmp;
		cnt[a[i]+m]++;
		cnt[a[i]+m-tmp]--;
	}
	
	//ll fr[2*m];
	ll num = 0;
	//memset(fr, 0, sizeof(fr));
	rrep(i, 2*m-1, 1){
		num += cnt[i];
		g[i] -= num;
		//fr[i] += g[i];
		if(i > 0){
			g[i-1] += g[i];
		}
	}
	//printa(g, 0, 2*m-1)
	//printa(cnt, 0, 2*m-1)
	//printa(fr, 0, 2*m-1)
	ll ans = INF;
	zep(i, 0, m){
		ans = min(up-g[i]-g[i+m], ans);
	}
	print(ans)
	return 0;
}