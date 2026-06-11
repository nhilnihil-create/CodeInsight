#include <bits/stdc++.h>

#define MOD 1000000007
using namespace std ;

int n ;

const int MAXN = 100010 ;

int x[MAXN] ; 

int v[MAXN << 1] ; 

int main() {
#ifdef YJQ_LOCAL
		freopen(".in", "r", stdin) ;
#endif
		scanf("%d", &n) ; 
		for (int i = 1; i <= n; i ++) {
				scanf("%d", &x[i]) ; 
				if (x[i] <= 2 * n) v[x[i]] ++ ; 
		}
		for (int i = 1; i <= 2 * n + 2; i ++) v[i] += v[i - 1] ; 
		int now = 0 , ans = 1;  
		for (int i = 1; i <= n; i ++) {
				while (now <= 2 * n && v[now] - (i - 1) <= (now / 2)) now += 2 ; 
			    if (v[now] - (i - 1) > (now / 2)) {
						int cnt = v[now] ; 
						ans = 1LL * ans * (cnt - (i - 1)) % MOD ; 
				}	
				else ans = 1LL * ans * (n - (i - 1)) % MOD ; 
		}
		printf("%d\n", ans) ; 
}


