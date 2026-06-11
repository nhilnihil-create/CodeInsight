#include<bits/stdc++.h>

using namespace std ;

int a[200000] , n , R[200000] ;
bool cmp(int a , int b){
    return a > b ;
}
int main()
{
    scanf("%d" , &n ) ;

    for(int i = 1 ; i <= n ; i++ ) scanf("%d" , &a[i] ) ;
    sort( a + 1 , a + n + 1 , cmp ) ;
    for(int i = 1 ; i <= n ; i++ ){
        if( a[i] < i ){
            int t = a[i - 1] - ( i - 1 ) ;
            int j = i ;
            while( a[j] >= i - 1 && j <= n ) j++ ;
            j-- ;
            if( ( t % 2 == 0 ) && ( j - i + 1 ) % 2 == 0 ) printf("Second\n") ;
            else printf("First\n") ;
            return 0 ;
        }
    }
    if( a[n] >= n ){
        int t = a[n] - n ;
        if( t % 2 == 0 ) printf("Second\n") ;
        else printf("First\n") ;
    }
}