#include<bits/stdc++.h>
#define MAXN 200005
using namespace std ;	int n ; 

int a[MAXN] ;

int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a ;
}

inline bool check() {
	int ce = 0 , co = 0 , c1 = 0 ;
	long long sum = 0 ;
	int pos = 0 ;
	for (int i=1; i<=n; ++i)
		if ( a[i] & 1 )
			++co, pos = i , c1 += (a[i] == 1) , sum += a[i] ;
		else	++ce, sum += a[i] ;
	if ( c1 )	return ( sum - n ) & 1 ;
	if ( co == n )	return 0 ;
	if ( ce & 1 )	return 1 ;
	if ( (!( ce&1 )) && co > 1 )	return 0 ;
	--a[pos] ;
	int d = a[1] ;
	for (int i=2; i<=n; ++i)	d = gcd(d,a[i]) ;
	for (int i=1; i<=n; ++i)	a[i] /= d ;
	return check()^1 ;
}

int main() {
	scanf("%d",&n) ;
	for (int i=1; i<=n; ++i)	scanf("%d",a+i) ;
	puts(check()? "First":"Second") ;
	return 0 ;
}
