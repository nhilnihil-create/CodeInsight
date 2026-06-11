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

ll a[N] , b[N] , n ;
bool ok(ll x) {
	for (int i = 1 ; i <= 2 * n - 1 ; i ++) {
		if (a[i] >= x) b[i] = 1 ;
		else b[i] = 0 ;
	}
	for (int i = 0 ; i < n - 1 ; i ++) {
		if (b[n + i] == b[n + i + 1]) return b[i + n] ;
		if (b[n - i] == b[n - i - 1]) return b[n - i] ;
	}
	if (n % 2  == 0)return !b[n] ;
	else return b[n] ;
}
int main () {
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> n ;
    for (int i = 1;  i <= 2 * n - 1 ; i ++) cin >> a[i] ;
    ll h = 3 * n + 10 , l = -1 , m ;
    while (h - l > 1) {
    	m = (h + l) >> 1 ;
    	if (ok(m)) l= m ;
    	else h = m ;
	}
	//cout << ok(2) << endl;
	if (ok(l)) h = l;
	cout << h; 
    return (0) ;
}