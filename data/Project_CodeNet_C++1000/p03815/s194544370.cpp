#include <bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

//ll gcd(int a, int b){ return b? gcd(b,a%b) : a ; } 

int main(){
    ll x ;
    cin >> x ;
    ll ans = 0  ;
    ans += x/11 ;
    ans *= 2    ;
    x %= 11     ;
    if( x == 0 )cout << ans  << endl;
    else if( x <= 6 )cout << ans + 1 << endl;
    else cout << ans + 2 << endl;
} 