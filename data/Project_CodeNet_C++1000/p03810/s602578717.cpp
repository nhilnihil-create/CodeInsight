#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll ;
#define rep(i, a, b) for (int i = a; i <= b; ++ i) 
const int N = 1e5 + 5 ;
using namespace std ;

int n, a[N] ;

int gcd(int x, int y) {
	return (y ? gcd(y, x % y) : x) ;
}

bool solve() {
	int cnt[2] = {0} ;
	rep(i, 1, n) ++ cnt[a[i] & 1] ;
	if ((cnt[0] & 1)) return true ;
	if (cnt[1] > 1 || cnt[0] + cnt[1] == 1) return false ;
	rep(i, 1, n) if (a[i] & 1) {
		if (a[i] > 1) -- a[i] ; else return false ;	
	}
	int x = a[1] ;
	rep(i, 2, n) x = gcd(x, a[i]) ;
	rep(i, 1, n) a[i] /= x ;
	return !solve() ;
}

int main() {
	scanf("%d", &n) ;
	rep(i, 1, n) scanf("%d", &a[i]) ;
	if (solve()) printf("First\n") ; else printf("Second\n") ;
	return 0 ; 
}