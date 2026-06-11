//              +-- -- --++-- +-In the name of ALLAH-+ --++-- -- --+              \\

#include <bits/stdc++.h>

#define int ll

#define F first
#define S second
#define _sz(x) (int)x.size()

using namespace std ;
using ll = long long ;
using ld = long double ;
using pii = pair <int , int> ;

const int N = 1e5 + 20 ;
int n , a[N] ;
vector <int> g[N] ;

inline void err () {
	cout << "NO\n" ;
	exit(0) ;
}

int dfs (int v , int par = -1) {
	if (_sz(g[v]) == 1) return a[v] ;

	int sum = 0 , mx = 0 ;
	for (int u : g[v])
		if (u != par) {
			int val = dfs(u , v) ;
			sum += val ;
			mx = max(mx , val) ;
		}

	if (a[v] > sum || (sum - a[v]) > min(sum / 2 , sum - mx)) err() ;

	return 2 * a[v] - sum ; 
}

int32_t main(){
	ios::sync_with_stdio(false) , cin.tie(0) , cout.tie(0) ;

	cin >> n ;
	for (int i = 0 ; i < n ; i ++) cin >> a[i] ;

	for (int i = 0 , u , v ; i < n - 1 ; i ++) {
		cin >> u >> v ;
		u -- , v -- ;
		g[u].push_back(v) ;
		g[v].push_back(u) ;
	}

	if (n == 2) {
		return cout << (a[0] == a[1] ? "YES" : "NO") << '\n' , 0 ;
	}

	int root = -1 ;
	for (int i = 0 ; i < n ; i ++) 
		if (_sz(g[i]) > 1) root = i ;

	if (dfs(root)) err() ;

	cout << "YES\n" ;
}
