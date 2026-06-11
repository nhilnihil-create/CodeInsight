#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll ; 
typedef long double ld ;
typedef pair<ll , ll> pll ;

const ll N = 2e5 + 30 , Mod = 1e9 + 7 ;
const ll SQ = 330 ;

ll cnt[N] ;
int main () {
    ios::sync_with_stdio(0), cin.tie(0) ;
    ll n ;
    cin >> n ;
    vector<ll> v ;
    for (int i = 0 ; i < n ;i  ++) {
    	ll x ;
    	cin >> x ;
    	v.pb(x) ;
    	cnt[x] ++ ;
	}
	sort(all(v)) ;
	if (v.back() - v[0] > 1) return cout << "No" , 0 ;
	if (v.back() == v[0]) {
		if (v[0] == n - 1 || 2 * v[0] <= n) cout << "Yes" ;
		else cout << "No" ;
		exit(0) ;
	}
	ll x = cnt[v[0]] , y = cnt[v.back()] ;
    if (v.back() >= x + 1 && v.back() <= x + (y / 2) ) cout << "Yes" ;
    else cout << "No" ;
    return (0) ;
}