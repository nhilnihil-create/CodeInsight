#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N; int ans = 1;
  
  bool increaseCase = false, decreaseCase = false;
  
  vector<int64_t> vec(N);
  
  for (int i = 0; i < N; i++) cin >> vec[i];
  
  for (int i = 0; i < N - 1; i++) {
    
    int tmp = vec[i], next = vec[i + 1];
    
    if (tmp < next) {
      
      if (increaseCase == false && decreaseCase == false) {
        increaseCase = true;
      }
      
      if (decreaseCase == true) {
        ans++; decreaseCase = false;
      }
      
    }
    
    if (next < tmp) {
      
      if (increaseCase == false && decreaseCase == false) {
        decreaseCase = true;
      }
      
      if (increaseCase == true) {
        ans++; increaseCase = false;
      }
      
    }
    
  }
  
  cout << ans << endl;
  
}