#include <bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

int main(){
    ll n , m ;
    cin >> n >> m ;
    vector<string> S(n) , T(m) ;
    rep(i,n) cin >> S[i] ;
    rep(i,m) cin >> T[i] ;
    for(int i = 0 ; i < n - m + 1 ; i++ ){
        for(int j = 0 ; j < n - m + 1 ; j++ ){
            ll count = 0 ;            
            rep(k,m){
                rep(l,m){
                    if( S[ i + k ][ j + l ] == T[k][l] )count++ ;
                }
            }
            if( count == m * m ){
                cout << "Yes" << endl ;
                return 0 ;
            }
            //else cout << count << endl ;
        }
    }
    cout << "No" << endl ;
}