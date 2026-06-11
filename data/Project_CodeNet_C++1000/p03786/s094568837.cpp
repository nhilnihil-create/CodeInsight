#include<bits/stdc++.h>
using namespace std ;
#define Next( i, x ) for( register int i = head[x]; i; i = e[i].next )
#define rep( i, s, t ) for( register int i = (s); i <= (t); ++ i )
#define drep( i, s, t ) for( register int i = (t); i >= (s); -- i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 1e5 + 5 ; 
int n, A[N] ;  
bool check( int x ) {
	int u = A[x] ; 
	for( re int i = 1; i <= n; ++ i ) {
		if( x == i ) continue ; 
		if( u * 2 < A[i] ) return 0 ;
		u += A[i] ; 
	}
	return 1 ; 
} 
signed main()
{
	n = gi() ; 
	rep( i, 1, n ) A[i] = gi() ; 
	sort( A + 1, A + n + 1 ) ; 
	int l = 1, r = n, ans = n ;
	while( l <= r ) {
		int mid = ( l + r ) >> 1 ; 
		if( check(mid) ) r = mid - 1, ans = mid ; 
		else l = mid + 1 ; 
	} 
	printf("%lld\n", ( n - ans + 1 ) ) ; 
	return 0 ;
}