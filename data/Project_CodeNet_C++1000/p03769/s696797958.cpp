#include<bits/stdc++.h>
using namespace std ;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
#define int long long
int gi() {
	char cc = getchar() ; int cn = 0, flus = 1 ;
	while( cc < '0' || cc > '9' ) {  if( cc == '-' ) flus = - flus ; cc = getchar() ; }
	while( cc >= '0' && cc <= '9' )  cn = cn * 10 + cc - '0', cc = getchar() ;
	return cn * flus ;
}
const int N = 100 + 5 ;
int a[N << 1], n, he, ed, cnt ; 
signed main()
{
	n = gi() + 1 ; 
	ed = 99, he = 100, cnt = 0 ; int flag = 0 ;
	for( re int i = 50; i >= 0; -- i ) {
		int u = ( 1ll << i ) ;
		if( n & u ) {
			if( !flag ) flag = 1 ;
			else {
				a[++ ed] = ++ cnt, a[-- he] = ++ cnt ; 
			}
		}
		else if( !flag ) continue ; 
		else {
			a[++ ed] = ++ cnt ; 
		}
	}
	printf("%lld\n", cnt * 2 ) ;
	rep( i, he, ed ) printf("%lld ", a[i] ) ;
	rep( i, 1, cnt ) printf("%lld ", i ) ;
	return 0 ; 
}