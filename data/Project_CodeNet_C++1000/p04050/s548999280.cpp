#include <bits/stdc++.h>
using namespace std ;
void Read ( int &x, char c = getchar(), bool f = 0 ) {
	for ( x = 0 ; !isdigit(c) ; c = getchar() ) if (c == '-') f = 1 ;
	for ( ; isdigit(c) ; c = getchar() ) x = 10*x + c - '0' ;
	if (f) x = -x ;
}
const int maxN = 105 ;
int n, m, a[maxN] ;
int main() {
	int i, x, y, tot = 0 ;
	Read(n) ; Read(m) ;
	for ( i = 1 ; i <= m ; i ++ ) Read(a[i]) ;
	x = 1 ; y = m ;
	for ( i = 1 ; i <= m ; i ++ )
		if (a[i]&1) {
			++tot ;
			if (tot == 1) x = i ;
			else y = i ;
		}
	swap(a[1], a[x]) ;
	swap(a[y], a[m]) ;
	if (tot > 2) {
		puts("Impossible") ;
		return 0 ;
	}
	if (m == 1) {
		printf ( "%d\n", a[1] ) ;
		if (a[1] == 1) {
			puts("1\n1") ;
			return 0 ; 
		}
		puts("2") ;
		printf ( "1 %d\n", a[1]-1 ) ;
		return 0 ;
	}
	for ( i = 1 ; i <= m ; i ++ ) printf ( "%d ", a[i] ) ;
	puts("") ;
	a[1] ++ ; a[m] -- ;
	if (a[m] == 0) -- m ;
	printf ( "%d\n", m ) ;
	for ( i = 1 ; i <= m ; i ++ ) printf ( "%d ", a[i] ) ;
	return 0 ;
}