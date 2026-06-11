#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll ; 
typedef long double ld ;
typedef pair<ll , ll> pll ;

const ll N = 2e3 + 30 , Mod = 1e9 + 7 ;
const ll SQ = 330 ;

ll n , k ;
vector<ll> G[N] ;
vector<pll> E ;
ll d[N][N] , d2[N] ;
void bfs(ll x) {
	d[x][x] = 0 ;
	queue<ll> q ;
	q.push(x) ;
	while (q.size()) {
		ll v = q.front() ;
		q.pop() ;
		for (auto u : G[v]) {
			if (d[x][u] > d[x][v] + 1) {
				d[x][u] = d[x][v] + 1 ;
				q.push(u) ;
			}
		}
	}
	
}
void solve1() {
	ll ans = 1e18 ;
	for (int i = 0 ; i < n - 1  ; i ++) {
		memset(d2 , 63, sizeof(d2)) ;
		queue<ll> q ;
		d2[E[i].F] = d2[E[i].S] = 0 ;
		q.push(E[i].F) ;
		q.push(E[i].S) ;
		while (q.size()) {
			ll v = q.front() ;
			q.pop() ;
			for (auto u : G[v]) {
				if (d2[u] > d2[v] + 1) {
					d2[u] = d2[v] + 1 ;
					q.push(u) ;
				}
			}
		}
		ll cur = 0 ;
		for (int i =  1 ; i <= n ; i ++) if (d2[i] > (k - 1) / 2) cur ++ ;
		ans = min(ans , cur ) ; 
	}
	cout << ans ;
	exit(0) ;
}
void solve2() {
	ll ans = 1e18 ;
	for (int i = 1 ; i <= n ; i ++) {
		ll cur = 0 ;
		for (int j = 1 ; j <= n ; j ++) {
			if (d[i][j] > (k / 2)) cur ++ ;
		}
		ans = min(ans , cur) ;
	}
	cout << ans ;
	exit(0) ;
}
int main () {
    ios::sync_with_stdio(0), cin.tie(0) ;
    cin >> n >> k ;
    for (int i = 0 ; i < n  - 1; i ++) {
    	ll v , u ;
    	cin >> v >> u ;
    	G[v].pb(u) ;
    	G[u].pb(v) ;
    	E.pb({v , u}) ;
	}
	memset(d , 63 , sizeof(d)) ;
	for (int i = 1  ; i <= n ; i ++) bfs(i) ;
	if (k & 1) solve1() ;
	else solve2() ;
    
    return (0) ;
}