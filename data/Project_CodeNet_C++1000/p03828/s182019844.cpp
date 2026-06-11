#include <bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

const int MOD = 1e9 + 7 ;

map<int,int> PF( int n ){
    map<int,int> ret ;
    for(int i = 2 ; i*i <= n ; i++ ){
        if(n%i) continue ;
        while(n%i==0) {
            ret[i]++ ;
            n /= i ; 
        }
    }
    if( n != 1 ) ret[n] = 1 ;
    return ret ;
}

int main(){
    int n ;
    cin >> n ;
    map<int,int> mp ;
    for(int i = 1 ; i <= n ; i++ ){
        map<int,int> count = PF(i) ;
        for(auto p : count){
            int a = p.first  ;
            int b = p.second ;
            mp[a] += b ; 
        }
    }
    ll ans = 1 ;
    for(auto p : mp ){
            int a = p.first  ;
            int b = p.second ;
            ans *= mp[a] + 1 ;
            ans %= MOD ; 
    }
    cout << ans % MOD << endl;
}
