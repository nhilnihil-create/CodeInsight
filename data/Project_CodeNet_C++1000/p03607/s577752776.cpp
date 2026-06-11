#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N; cin >> N; int ans = 0, count = 1;
  
  vector<int64_t> vec(N);
  
  for (int i = 0; i < N; i++) cin >> vec[i];
  
  sort(vec.begin(), vec.end());
  
  for (int i = 0; i < N - 1; i++) {
    
    if (i == N - 2) {
      
      if (vec[i] == vec[i + 1]) count++;
      
      else ans++;
      
      if (count % 2 == 1) ans++;
      
      break;
      
    }
    
    if (vec[i] == vec[i + 1]) count++;
    
    else {
      if (count % 2 == 1) ans++;
      count = 1;
    }
    
  }
  
  cout << ans << endl;
  
}