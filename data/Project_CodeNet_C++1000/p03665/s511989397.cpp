#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, P; cin >> N >> P;
  
  bool flag = false;
  
  for (int i = 0; i < N; i++) {
    int A; cin >> A;
    if (A % 2 == 1) flag = true;
  }
  
  if (flag) cout << int64_t(pow(2, N - 1)) << endl;
  
  else {
    
    if (P == 0) cout << int64_t(pow(2, N)) << endl;
    
    else cout << 0 << endl;
    
  }
  
}