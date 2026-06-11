#include <bits/stdc++.h>

using namespace std;


long long noNum , a , b , c  ;
long long v [ 100100 ] ;

int solve ( int noMoves ){
    int temp = noMoves ;


    for ( int i = 0 ; i < noNum ; i++ ){

        long long x = v [ i ] - b * noMoves ;

        if ( x < 0 ){
            continue ;
        }

        long long crMoves = x / c + 1 ;

        if ( x % c == 0 ){
            crMoves -- ;
        }

        temp -= crMoves ;

        if ( temp < 0 ){
            return 0 ;
        }

    }
    return 1 ;


}

int main(){

    scanf("%I64d%I64d%I64d",&noNum , &a , &b );

    c = a - b ;

    for ( int i = 0 ; i < noNum ; i++ ){
        scanf("%I64d",&v [ i ]);
    }

    int leftIndex = 1 , rightIndex = 1e9 ;

    while ( leftIndex < rightIndex ){
        int midIndex = ( leftIndex + rightIndex ) / 2 ;

        int val = solve ( midIndex) ;

        if ( val == 0 ){
            leftIndex = midIndex + 1;
        }else{
            rightIndex = midIndex ;
        }

    }

    printf("%d",leftIndex);

    return 0;
}
