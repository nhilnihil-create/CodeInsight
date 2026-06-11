//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define F first
#define S second
#define _sz(x) (int)x.size()

using namespace std ;
using ll = long long ;
using ld = long double ;
using pii = pair <int , int> ;

const int N = 5000 + 20 , mod = 1e9 + 7 ;
int n , dp[N][N] , ans ;
string s ;

inline void rel (int &a) {
	if (a >= mod) a -= mod ;
}

inline void add (int &a , int b) {
	rel(b) ;
	a += b ;
	rel(a) ;
}

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> n ;
	cin >> s ;

	dp[0][0] = 1 ;
	for (int i = 0 ; i < n ; i ++) {
		for (int j = 0 ; j <= i ; j ++) {
			add(dp[i + 1][j + 1] , 2 * dp[i][j]) ;
			add(dp[i + 1][max(0 , j - 1)] , dp[i][j]) ;
		}
	}

	ans = dp[n][_sz(s)] ;

	for (int i = 0 ; i < _sz(s) ; i ++) ans = 1ll * ans * (mod + 1) / 2 % mod ;

	cout << ans << '\n' ;
}
