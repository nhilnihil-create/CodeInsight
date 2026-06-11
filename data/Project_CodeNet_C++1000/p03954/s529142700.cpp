#include <iostream>
#include <cstdlib>
#include <cstdio>
#define mid ( ( l + r ) >> 1 )

const int N = 2e5 + 5 ;

int n , v[N] ;

inline bool check ( int x ) { // true 偏大左移 , false 偏小右移 
	for (int i = 0 ; i < n - 1 ; ++ i) {
		if ( ( v[n+i] > x && v[n+i+1] > x ) || ( v[n-i] > x && v[n-i-1] > x ) ) return false ;
		if ( ( v[n+i] <= x && v[n+i+1] <= x ) || ( v[n-i] <= x && v[n-i-1] <= x ) ) return true ;
	}
	return ( v[1] <= x && v[1] <= x ) ;
}

int main () {
	scanf ("%d" , & n ) ;
	for (int i = 1 ; i < ( n << 1 ) ; ++ i) scanf ("%d" , & v[i] ) ;
	int l = 1 , r = ( n << 1 ) - 1 ;
	while ( l < r ) {
		if ( check ( mid ) ) r = mid ;
		else l = mid + 1 ;
	}
	printf ("%d\n" , r ) ;
	return 0 ;
}