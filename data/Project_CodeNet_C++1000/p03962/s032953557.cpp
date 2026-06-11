#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b, c;
  bool have;
  int ans;
  cin >> a >> b >> c;
  if(a == b){
    if(b == c) ans = 1;
    else ans = 2;
  }
  else if(a == c){
    ans = 2;
  }
  else if(b == c) ans = 2;
  else ans = 3;
  cout << ans << endl;
  return 0;
}
