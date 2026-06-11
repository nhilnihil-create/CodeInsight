#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int ans=3;

  if(a==b){
    ans--;
  }
  if(b==c){
    ans--;
  }
  if(c==a){
    ans--;
  }

  if(ans==0){
    cout << 1 << endl;
  }
  else{
    cout << ans << endl;
}

return 0;  
}