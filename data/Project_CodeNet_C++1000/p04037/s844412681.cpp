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
const int N = 1e5 + 5 ;
int a[N], n ;
bool cmp( int x, int y ) {
	return x > y ; 
}
signed main()
{
	n = read(); rep( i, 1, n ) a[i] = read() ; 
	sort( a + 1, a + n + 1, cmp ) ; 
	int ans ; 
	rep( i, 1, n ) {
		if( a[i + 1] < ( i + 1 ) ) {
			ans = ( a[i] - i ) % 2 ;
			int flag = 0 ; 
			for( re int j = i + 1; j <= n; ++ j ) {
				if( a[j] == ( i ) ) ++ flag ; 
			}
			ans = max( ans, flag % 2 ) ;
			break ;
		}
	}
	if( ans ) puts("First");
	else puts("Second");
	return 0;
}