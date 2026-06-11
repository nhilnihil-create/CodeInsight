#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N; int64_t sum = 0;
  
  vector<int64_t> vecA(N), vecB(N);
  
  for (int i = 0; i < N; i++) {
    
    int64_t A, B; cin >> A >> B;
    
    vecA[i] = A; vecB[i] = B;
    
  }
  
  for (int i = N - 1; 0 <= i; i--) {
    
    int64_t tmp = vecA[i] + sum;
    
    if (tmp % vecB[i] != 0) {
      
      sum += vecB[i] * (tmp / vecB[i] + 1) - tmp;
      
    }
    
  }
  
  cout << sum << endl;
  
}