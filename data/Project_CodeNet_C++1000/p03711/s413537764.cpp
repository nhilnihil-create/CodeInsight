#include <bits/stdc++.h>
using namespace  std;
#define ll long long 
int main(){
    set<ll> s1 = { 1, 3 , 5 , 7 , 8 , 10 , 12 }  ;
    set<ll> s2 = { 4 , 6 , 9 , 11 } ;
    set<ll> s3 = { 2 } ;
    ll x , y ;
    cin >> x >> y ;
    if ( s1.find(x) != s1.end() && s1.find(y) != s1.end() ){
        cout << "Yes" ; return 0;
    }
      if ( s2.find(x) != s2.end() && s2.find(y) != s2.end() ){
        cout << "Yes" ; return 0;
    }
      if ( s3.find(x) != s3.end() && s3.find(y) != s3.end() ){
        cout << "Yes" ; return 0;
    }
    cout << "No" ;
}