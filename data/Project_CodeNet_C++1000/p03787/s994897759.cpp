#include <bits/stdc++.h>
using namespace std ; 
 
const int MAXN = 1e6 + 100 ; 
#define int long long
int vis[MAXN] , bd , sz ;
vector<int> ver[MAXN] ; 
void dfs(int v , int col = 1) {
	vis[v] = col ; 
	for(auto u : ver[v]){
		if(vis[u] == col){bd = false ; continue ; }
		if(! vis[u]) dfs(u , 3 - col) ; 
	}
	sz ++ ;
}
int32_t main(){
    ios_base::sync_with_stdio(0) ; 
    cin . tie(0) , cout . tie(0) ; 
    
    int n , m ; cin >> n >> m ; 
    for(int i = 0 ; i < m ; i ++){
    	int x , y ; cin >> x >> y ; 
    	x -- , y -- ; 
    	ver[x] . push_back(y) ; 
    	ver[y] . push_back(x) ;
    }
    int a = 0 , b = 0 , c = 0 ; 
    for(int i = 0 ; i < n ; i ++){
    	if(vis[i]) continue ; 
    	sz = 0 , bd = true ; 
    	dfs(i) ; 
    	if(sz > 1 && bd)b ++ ;
    	else if(sz > 1) a ++ ; 
    	else c ++ ; 
    }
    cerr << a << ' ' << b << ' ' << c << '\n' ; 
    int ans = a * a + b * b * 2 + 2 * a * b + c * (n - c) * 2 + c * c ;
    cout << ans ; 
 
}