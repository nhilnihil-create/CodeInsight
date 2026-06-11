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
int n , gnd[N] ;
vector <int> g[N] ;

void dfs (int v , int par = -1) {
	for (int u : g[v]) {
		if (u == par) continue ;

		dfs(u , v) ;

		gnd[v] ^= (gnd[u] + 1) ;
	}
}

int main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> n ;

	for (int i = 0 , u , v ; i < n - 1 ; i ++) {
		cin >> u >> v ;
		u -- , v -- ;

		g[u].push_back(v) ;
		g[v].push_back(u) ;
	}

	dfs(0) ;

	cout << (gnd[0] ? "Alice" : "Bob") << '\n' ;
}
