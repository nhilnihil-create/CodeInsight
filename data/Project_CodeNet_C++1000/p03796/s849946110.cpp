#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

int main() {
    int n ;
    cin >> n ;
    ll ans = 1 ;
    rep(i,n){
        ans *= i + 1 ;
        ans %= (ll) 1e9 + 7 ;
    }
    cout << ans << endl;
}
    
