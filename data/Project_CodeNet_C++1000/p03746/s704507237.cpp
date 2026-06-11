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

ll p[N] , M[N];
vector<ll> G[N] ;

int main () {
    ios::sync_with_stdio(0), cin.tie(0) ;
    ll n , m ;
    cin >> n >> m ;
    deque<ll> q ;
    while (m --) {
    	ll v,  u ;
    	cin >> v >> u ;
    	G[v].pb(u) ;
    	G[u].pb(v) ;
    	if (!m) {
    		q.pb(v) ;
    		q.pb(u) ;
    		M[v] = M[u] = 1 ;
		}
	}
	while (true) {
		ll v = q.front() ;
		ll u = q.back() ;
		ll ok = 0 ;
		for (auto k : G[v]) {
			if (!M[k]) {
				M[k] = 1; 
				q.push_front(k) ;
				ok ++ ;
				break;
			}
		}
		for (auto k : G[u]){
			if (!M[k]) {
				M[k ] = 1 ;
				q.pb(k); 
				ok ++ ;
				break;
			}
			
		}
		if (!ok) break;
		
	}
	cout << q.size() << '\n' ;
	for (int i = 0 ; i < q.size() ; i ++) cout << q[i] << ' ' ;
    return (0) ;
}