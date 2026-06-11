#include <bits/stdc++.h> 
using namespace std;
 
int main(void) {
  int K, S, ans = 0;
  cin >> K >> S;
  for (int x = 0; x <= K; x++) {
    for (int y = 0; y <= K; y++) {
      if (S - x -y <= K && x + y <= S) {
        ans++;
      }
    }
  }
  
  
  cout << ans << endl;
}