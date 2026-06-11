#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef long long ll ;
#define rep(i, a, b) for (int i = a; i <= b; ++ i) 
using namespace std ;

int d[500], opt[500] ;
ll n ;

int main() {
	scanf("%lld", &n) ;
	int k = 0 ; ll tmp = n + 1 ;
	for ( ; tmp ; ++ k) if (tmp & 1LL) -- tmp, d[k] = 0 ; else tmp /= 2, d[k] = 1 ;
	int he = k, ta = he - 1 ;
	int top = 0 ;
	for (int i = k - 2 ; i >= 0; -- i) if (d[i]) opt[++ ta] = ++ top ; else opt[-- he] = ++ top ;
	printf("%d\n", k * 2 - 2) ;
	rep(i, he, ta) printf("%d ", opt[i]) ;
	rep(i, 1, k - 1) printf("%d ", i) ;

	return 0 ; 
}