//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define F first
#define S second
#define _sz(x) (int)x.size()

using namespace std ;
using ll = long long ;
using ld = long double ;
using pii = pair <int , int> ;

const int N = 1e5 + 20 ;
int n , k , a[N] , ans ;
vector <int> g[N] ;

int dfs (int v , int par = -1) {
	int d = 0 ;
	for (int u : g[v]) {
		d = max(d , dfs(u , v)) ;
	}

	if (d == k - 1 && par > 0) ans ++ , d = -1 ;

	return d + 1 ;
}

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> n >> k ;

	for (int i = 0 ; i < n ; i ++) {
		cin >> a[i] ;
		a[i] -- ;
		if (i) g[a[i]].push_back(i) ;
	}

	ans += (a[0] > 0) ;

	dfs(0) ;

	cout << ans << '\n' ;
}
