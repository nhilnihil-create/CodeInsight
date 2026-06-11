#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll ;
#define rep(i, a, b) for (int i = a; i <= b; ++ i) 
const int N = 1e5 + 5 ;
using namespace std ;

int n, e, ter[N << 1], lnk[N], nxt[N << 1] ;

void add(int x, int y) {
	ter[++ e] = y, nxt[e] = lnk[x], lnk[x] = e ;
}

int dfs(int p, int las) {
	int res = 0 ;
	for (int i = lnk[p] ; i; i = nxt[i]) if (ter[i] != las) {
		res ^= dfs(ter[i], p) + 1 ;
	}
	return res ;
}

int main() {
	scanf("%d", &n) ;
	int x, y ;
	rep(i, 1, n - 1) {
		scanf("%d%d", &x, &y) ;
		add(x, y), add(y, x) ;
	}
	puts(dfs(1, 0) ? "Alice" : "Bob") ;
	return 0 ; 
}