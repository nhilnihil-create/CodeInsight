#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;

int main() {
  int k,s;
  cin >> k >> s;
  
  int ans = 0;
  
  int z = 0;
  REP(x,k+1){
    REP(y,k+1){
      z = s - x - y;
      if(x + y + z == s && z >= 0 && z <= k){
        ans++;
      }
     
    }
  }
        
  
  cout << ans << endl;

}