// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
#define rep( i, s, t ) for( register int i = s; i <= t; ++ i )
#define re register
int read() {
	char cc = getchar(); int cn = 0, flus = 1;
	while(cc < '0' || cc > '9') {  if( cc == '-' ) flus = -flus;  cc = getchar();  }
	while(cc >= '0' && cc <= '9')  cn = cn * 10 + cc - '0', cc = getchar();
	return cn * flus;
}
const int N = 2e5 + 5 ; 
int a[N], sz, n, b[N] ; 
bool check( int x ) {
	rep( i, 1, sz ) b[i] = ( a[i] >= x ) ; 
	int wh1 = 0, wh2 = 0, b1, b2 ; 
	for( int k = 1; k < n; ++ k ) {
		if( ( b[n - k] == 0 && b[n - k + 1] == b[n - k] ) || ( b[n + k] == 0 && b[n + k - 1] == b[n + k] ) ) return 0 ; 
		if( ( b[n - k] == 1 && b[n - k + 1] == b[n - k] ) || ( b[n + k] == 1 && b[n + k - 1] == b[n + k] ) ) return 1 ; 
	}
	return b[1] ; 
} 
signed main()
{
	n = read() ; sz = 2 * n - 1 ; 
	rep( i, 1, sz ) a[i] = read() ;
	if( n == 1 ) { printf("%d\n", a[n] ) ; return 0; }
	int l = 1, r = sz, ans, mid ; 
	while( l <= r ) {
		mid = ( l + r ) >> 1 ; 
		if( check(mid) ) ans = mid, l = mid + 1 ; 
		else r = mid - 1 ;
	}
	printf("%d\n", ans ) ;
	return 0;
}