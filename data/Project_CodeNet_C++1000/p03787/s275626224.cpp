#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll ;
#define rep(i, a, b) for (int i = a; i <= b; ++ i) 
const int N = 1e5 + 5, M = 4e5 + 5 ;
using namespace std ;

int n, m, e, ter[M], nxt[M], lnk[N], opt[N], f[N], cnt[3] ;
bool vis[N] ;

void add(int x, int y) {
	ter[++ e] = y, nxt[e] = lnk[x], lnk[x] = e ;
}

void solve(int x) {
	vis[x] = false ;
	int he = 0, ta = 1 ;
	opt[1] = x, f[x] = 1 ;
	for ( ; he != ta ; ) {
		int u = opt[++ he] ;
		for (int i = lnk[u]; i; i = nxt[i]) {
			f[ter[i]] |= (3 - f[u]) ;
			if (vis[ter[i]]) {
				vis[ter[i]] = false ;
				opt[++ ta] = ter[i] ;
			}
		}
	}
	if (ta == 1) {
		++ cnt[0] ;
		return ;
	}
	rep(i, 1, ta) if (f[opt[i]] == 3) {
		++ cnt[1] ;
		return ;
	}
	++ cnt[2] ;
}

int main() {
	scanf("%d%d", &n, &m) ;
	int x, y ;
	rep(i, 1, m) {
		scanf("%d%d", &x, &y) ;
		add(x, y), add(y, x) ;
	}
	rep(i, 1, n) vis[i] = true ;
	rep(i, 1, n) if (vis[i]) solve(i) ;
	ll ans = (ll) cnt[0] * (n - cnt[0]) * 2 + (ll) cnt[0] * cnt[0] + (ll) cnt[1] * cnt[2] * 2 + (ll) cnt[1] * cnt[1] + (ll) cnt[2] * cnt[2] * 2 ;
	printf("%lld\n", ans) ;
	return 0 ; 
}