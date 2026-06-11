#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int64_t A, B, C; cin >> A >> B >> C;
  
  int64_t dif1, dif2, dif3;
  
  dif1 = A * B; dif2 = B * C; dif3 = C * A;
  
  if (A % 2 == 0 || B % 2 == 0 || C % 2 == 0) cout << 0 << endl;
  
  else cout << min(dif1, min(dif2, dif3)) << endl;
  
}