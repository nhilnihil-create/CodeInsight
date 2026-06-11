#include <bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

int main(){
    ll n ;
    cin >> n ;
    string s ;
    cin >> s ;
    ll ans = 0 ;
    ll tem = 0 ;
    rep(i,n){
        if(s[i] == 'I')tem++ ;
        else tem-- ;
        ans = max(ans,tem) ;
    }
    cout << ans << endl;
}