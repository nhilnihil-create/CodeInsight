#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;
  
  map<int, int> S;
  
  for (int i = 2; i <= n; i++) {
    int x = i;
    for (int j = 2; j <= n; j++) {
      while(x%j == 0){
        S[j]++;
        x /= j;
      }
    }
  }
  
  int64_t ans = 1;
  for (auto x : S) {
    ans *= x.second + 1;
    ans %= 1000000007;
  }
  

  cout << ans << endl;

  
}
             
 