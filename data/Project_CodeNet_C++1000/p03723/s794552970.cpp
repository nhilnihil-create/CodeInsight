#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int A, B, C; cin >> A >> B >> C; int ans = 0;
  
  for (int i = 0; i < 10000; i++) {
    
    if (A % 2 == 1 || B % 2 == 1 || C % 2 == 1) {
      cout << ans << endl;
      return 0;
    }
    
    int tmpA = A; int tmpB = B; int tmpC = C;
    
    A = tmpB / 2 + tmpC / 2;
    B = tmpA / 2 + tmpC / 2;
    C = tmpA / 2 + tmpB / 2;
    
    ans++;
    
  }
  
  cout << -1 << endl;
  
}