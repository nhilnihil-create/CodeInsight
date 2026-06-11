#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i <= (int)(n); i++)
using namespace std;

int main(){
  int k,s;
  cin >> k >> s;
  
  int ans = 0;
  rep(x,k){
    rep(y,k){
      int z = s - (x + y);
      if(0 <= z && z <= k) ans++;
    }
  }
  
  cout << ans << endl;
}