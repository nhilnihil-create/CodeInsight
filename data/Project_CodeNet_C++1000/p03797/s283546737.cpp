#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0;i < (ll) (n); ++i)

int main(){
  ll s,c;
  cin >> s >> c;
  ll cc = 0;
  if( c%2 == 0 ){
    cc = c/2;
  }else{
    cc = c/2;
    c = 1;
  }
  
  if( cc >= s ){
    cout << ( s + cc )/2;
  }else{
    cout << min(s,cc) << endl;
  }
  return 0;
}