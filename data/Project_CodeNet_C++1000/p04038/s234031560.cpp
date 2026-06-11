#include<bits/stdc++.h>  
#define Rg register 
#define i60 long long 
#define fp( i , x , y ) for(Rg int i=(x); i<=(y); ++i) 
#define fq( i , x , y ) for(Rg int i=(y); i>=(x); --i) 
using namespace std ; 
const int hgs = 1e9+7 , N = 2005 ; 
i60 f[N][N] , n , k , fac[N*N] , inv[N*N] ; 
i60 power( i60 A , int B ) { 
    i60 tep = 1 ; 
    for( ; B ; B >>= 1 ) { 
        if( B&1 ) tep = tep * A % hgs ; 
        A = A * A % hgs ; 
	} return tep ;  } 
i60 C ( int A , int B ) { return A == 0 ? 1 : fac[B] * inv[A] % hgs * inv[B-A] % hgs ; }  
signed main( ) { 
    cin >> n >> k ;  fac[0] = 1 ; 
    if( k == 1 ) { cout << 1 << endl ; return 0 ; } 
    fp( i , 1 , n*k ) fac[i] = fac[i-1] * i % hgs ;  
    fp( i , 0 , n*k ) inv[i] = power( fac[i] , hgs-2 ) ;  
    fp( i , 1 , n ) f[i][0] = 1 ; 
    fp( i , 1 , n ) 
      fp( j , 1 , i ) 
	    f[i][j] = ( f[i-1][j] + f[i][j-1] 
		   * (n-j+1) % hgs * C( k-2 , n*k-i-(k-1)*(j-1)-1 ) ) % hgs ; 
	cout << f[n][n] << endl ; 
    return 0 ; 
} 