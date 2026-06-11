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

ll p[N] ;
int main () {
    ios::sync_with_stdio(0), cin.tie(0) ;
    ll n ;
    cin >> n ;
    for (int i = 1;  i <= n ;i ++) cin >> p[i];
    ll cnt = 0 ;
    ll ans = 0 ;
    for (int i = 1;  i <= n ; i ++) {
    	if (p[i] != i) {
    		ans += (cnt + 1) / 2 ;
    		cnt = 0 ;
		}
		else cnt ++ ;
	}
    cout << ans + (cnt + 1)  / 2 ;
    return (0) ;
}