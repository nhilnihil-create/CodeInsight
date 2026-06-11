#include <bits/stdc++.h>
using namespace std;

int main() {
  long long A, B;
  cin >> A >> B;
  long long ans;
  if (A*B < 0) ans = abs(A+B)+1;
  else {
    if (A < B) ans = B-A;
    else {
      ans = A-B+2;
      if (A*B == 0) ans -= 1;
    }
  }
  
  cout << ans << endl;
}