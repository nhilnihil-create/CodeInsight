#include<bits/stdc++.h>
using namespace std;
#pragma 03
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
typedef pair<int,int> ii ;
typedef vector<int> vi ;
 
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); cerr.tie(nullptr);
#define pb push_back
#define mp make_pair
#define ll long long
#define rep(i,a,n) for(int i = a ; i <= n ; i++ )
#define REP(i,a,n) for(int i = n ; i >= a ; i-- )
#define fi first
#define se second
const int N = 1e5+5 ;
const int mod = 1e9+7 ;
#define int long long
int n,m,t,ans[N] ;
pair<int , long long> a[N] ; 
signed main() {
	//freopen("BIGNUM.inp","r",stdin);
	//freopen("BIGNUM.out","w",stdout);
	cin >> n ;
	rep(i,1,n) {
		cin >> a[i].fi ;
		a[i].se = i ; 
	}
	sort(a+1,a+n+1) ;
	a[0].fi = 0 ; 
	a[0].se = 0 ;
	int j = n,idx=a[n].se ; 
	while(j>0) {
		int i ; 
		for(i = j ; i > 0 && a[i].fi == a[j].fi ; i-- ) {
			idx = min(idx,a[i].se) ;  
		}
		int cnt = n-i ; 
		ans[idx] += cnt*(a[i+1].fi-a[i].fi) ;
		j = i ; 
	} 
	rep(i,1,n) cout << ans[i] << endl ; 
}
 