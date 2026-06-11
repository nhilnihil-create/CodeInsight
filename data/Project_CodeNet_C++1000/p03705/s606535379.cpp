#include <bits/stdc++.h>

using namespace std;

int main() {
  long long N, A, B;
  
  cin >> N >> A >> B;
  
  if (B < A) {
    cout << 0 << endl;
    
    return 0;
  }
  
  long long min = A * (N - 1) + B;
  long long max = A + B * (N - 1);
  
  cout << (max - min + 1 > 0 ? (max - min + 1) : 0) << endl;
  
  return 0;
}