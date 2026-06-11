#include <bits/stdc++.h>

using namespace std ;

int main ()
{
    int cnt = 0 , a ;
    cin >> a ;
    int j = 1 ;
    while ( 1 ){
    cnt += j ;
        if ( cnt >= a ){
            cout << j ;
            break ;
        }
    j ++ ;
    }
}
