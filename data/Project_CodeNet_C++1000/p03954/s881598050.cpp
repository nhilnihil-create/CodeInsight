#include<bits/stdc++.h>

using namespace std ;

#define N 200007
#define inf 0x7fffffff

int n ;
int a[N] , b[N] ;

bool check(int x){
    for(int i = 1 ; i <= 2 * n - 1 ; i++ ) b[i] = ( a[i] >= x ) ;
    for(int i = 0 ; i <= n - 2 ; i++ ){
        if( (b[i + n] == 0 && b[i + n + 1] == 0) || (b[n - i] == 0 && b[n - i - 1] == 0 ) ) return 0 ;
        if( (b[i + n] == 1 && b[i + n + 1] == 1) || (b[n - i] == 1 && b[n - i - 1] == 1 ) ) return 1 ;
    }
    return b[1] ;
}

int main()
{
    scanf("%d" , &n ) ;

    int l = inf , r = -inf ;
    for(int i = 1 ; i <= 2 * n - 1 ; i++ ) scanf("%d" , &a[i] ) , l = min( l , a[i] ) , r = max( r , a[i] ) ;

    while( l < r ){
        int mid = ( l + r + 1 ) >> 1 ;
        if( check( mid ) ) l = mid ;
        else r = mid - 1 ;
    }
    printf("%d\n" , l ) ;
    return 0 ;
}