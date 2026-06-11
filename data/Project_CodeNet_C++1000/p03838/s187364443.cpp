#include <iostream>
using namespace std;
using ll = long long;
int main(){
  ll x,y;
  cin >> x >> y;
  ll ans;
  if((x>0 && y<0)||(x<0 && y>0)){
    ans = abs(abs(y)-abs(x))+1;
  }else if(y == 0){
    if(x<0) ans = abs(x);
    else ans = x+1;
  }else if(x == 0){
    if(y<0) ans = abs(y)+1;
    else ans = y;
  }else if(x < y){
    ans = y-x;
  }else{
    ans = x-y+2;
  }
  cout << ans << endl;
}
