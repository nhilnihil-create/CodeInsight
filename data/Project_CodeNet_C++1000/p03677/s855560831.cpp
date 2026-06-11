#include<bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 10 ;

int n, m ;

int a[N] ;

int sl[N] ;

long long S[N] ;

int FindShortestPath(int foo, int bar) {
	return (foo <= bar) ? bar - foo : bar + m - foo ;  
}

int main(){
	#define NAME "HSG10B" 
	//freopen(NAME".inp", "r", stdin) ; freopen(NAME".out", "w", stdout) ;

	cin >> n >> m ;

	for (int i = 1; i <= n; ++ i) cin >> a[i] ;

	long long sum = 0 ;
	
	for (int i = 1; i < n; ++ i) sum += 1ll * FindShortestPath(a[i], a[i + 1]) ;

	for (int i = 1; i < n; ++ i) {
		if (a[i] == a[i + 1]) continue ;
		long long foo = 1ll * FindShortestPath(a[i], a[i + 1]) ;
		if (a[i] < a[i + 1]) {
			foo += -1ll * (a[i + 1] + 1) ;
			sl[a[i] + 1] ++ ; sl[a[i + 1] + 1] -- ;
			S[a[i] + 1] += foo ; S[a[i + 1] + 1] -= foo ;
		}
		else {
			sl[a[i] + 1] ++ ; sl[1] ++ ; sl[a[i + 1] + 1] -- ;
			S[a[i] + 1] += foo - 1ll * (a[i + 1] + m + 1) ;
			S[1] += foo - 1ll * (a[i + 1] + 1) ;
			S[a[i + 1] + 1] -= foo - 1ll * (a[i + 1] + 1) ;
		}
	}	

	long long best = 0 ;

	for (int i = 1; i <= m; ++ i) {
		sl[i] += sl[i - 1] ; S[i] += S[i - 1] ;
		best = max(best, S[i] + 1ll * sl[i] * i) ;
	}

	cout << sum - best << endl ;

	return 0 ;
}