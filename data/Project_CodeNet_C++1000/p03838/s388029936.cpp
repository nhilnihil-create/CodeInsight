#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll x, y;  cin >> x >> y;
  ll ans = abs(abs(x)-abs(y));
  if(abs(x)==abs(y)){
    if(x!=y) ans +=1;
  }else if(x*y<0) ans += 1;
  else if(x*y==0 && y<x) ans += 1;
  else if(y<x) ans += 2;
  
  cout << ans << endl;
}
