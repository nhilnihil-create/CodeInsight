#include <bits/stdc++.h>

using namespace std;

int main(){
  long long x, y;
  cin >> x >> y;
  long long ans=0;
  if(abs(x)<abs(y)){
    if(x<0){
      x*=-1;
      ans++;
    }
    ans += abs(y) - x;
    x += abs(y) - x;
  }
  else if(abs(x)>abs(y)){
    if(x>0){
      x*=-1;
      ans++;
    }
    ans += -abs(y)-x;
    x += -abs(y)-x;
  }
  if(x!=y)ans++;
  cout << ans << endl;
}

