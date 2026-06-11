#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int64_t a, b; cin >> a >> b;
  
  if (0 < a) {
    cout << "Positive" << endl;
    return 0;
  }
  
  if (a <= 0 && 0 <= b) {
    cout << "Zero" << endl;
    return 0;
  }
  
  int64_t dif = abs(a - b);
  
  if (dif % 2 == 0) cout << "Negative" << endl;
  
  else cout << "Positive" << endl;
  
}