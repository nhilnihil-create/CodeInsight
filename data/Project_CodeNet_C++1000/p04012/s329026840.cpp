#include <bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ; i < n ; i++ )
typedef long long ll ;

int main(){
    string s ;
    cin >> s ;
    map<char,ll> mp ;
    rep(i,s.size()){
        mp[s[i]]++ ;
    }
    ll count = 0 , tem = 0 ;
    for(auto p :mp ){
        count++ ;
        if( p.second%2 == 0 )tem++ ;
    }
    if(count == tem )cout <<"Yes" <<endl ;
    else cout  << "No" << endl ;
}