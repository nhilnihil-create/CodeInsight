#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll ;
#define rep(i, a, b) for (int i = a; i <= b; ++ i) 
const int N = 200005 ;
using namespace std ;

int n, a[N], e, ter[N], nxt[N], lnk[N] ;

void add(int x, int y) {
	ter[++ e] = y, nxt[e] = lnk[x], lnk[x] = e ;
}

bool dfs(int p, int las) {
	ll sum = 0, mx = 0 ;
	bool flg = false ;
	for (int i = lnk[p]; i; i = nxt[i]) if (ter[i] != las) {
		if (!dfs(ter[i], p)) return false ;
		sum += a[ter[i]] ;
		mx = max(mx, (long long) a[ter[i]]) ;
		flg = true ;
	}
	if (!flg) {
		return true ;
	}
	if (sum < (long long) a[p]) return false ;
	if (2LL * a[p] < sum) return false ;
	if (sum - a[p] > sum / 2LL || sum - a[p] > sum - mx) return false ;
	a[p] -= sum - a[p] ;
	return true ;
}

int main() {
	scanf("%d", &n) ;
	rep(i, 1, n) scanf("%d", &a[i]) ;
	int x, y ;
	rep(i, 1, n - 1) {
		scanf("%d%d", &x, &y) ;
		add(x, y), add(y, x) ;
	}
	if (n == 2) {
		if (a[1] == a[2]) printf("YES\n") ; 
			else printf("NO\n") ;
		return 0 ;
	}
	int rt = 0 ;
	rep(i, 1, n) if (nxt[lnk[i]]) rt = i ;
//	printf("%d\n", rt) ;
	if (dfs(rt, 0) && !a[rt]) printf("YES\n") ; 
		else printf("NO\n") ;
	return 0 ; 
}