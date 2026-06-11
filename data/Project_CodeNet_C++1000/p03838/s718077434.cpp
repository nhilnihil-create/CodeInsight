#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main() {
  ll x,y;
  cin >> x >> y;
  ll ans = 0;
  
  if(x > 0 && y > 0){
    if(abs(x) <= abs(y)){
      ans = y-x;
    }else{
      ans = x-y+2;
    }
  }else if(x > 0 && y < 0){
    if(abs(x) <= abs(y)){
      ans = abs(y)-abs(x)+1;
    }else{
      ans = abs(x)-abs(y)+1;
    }
  }else if(x < 0 && y > 0){
    if(abs(x) <= abs(y)){
      ans = abs(y)-abs(x)+1;
    }else{
      ans = abs(x)-abs(y)+1;
    }    
  }else if(x < 0 && y < 0){
    if(abs(x) < abs(y)){
      ans = abs(y) - abs(x) + 2;
    }else{
      ans = abs(x) - abs(y);
    }    
  }else if(x > 0 && y == 0){
    ans = x + 1;
  }else if(x < 0 && y == 0){
    ans = abs(x);
  }else if(x == 0 && y > 0){
    ans = y;
  }else{
    ans = abs(y) + 1;
  }
  
  cout << ans << endl;
  
  return(0);
}