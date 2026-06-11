#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int64_t N, C, K; cin >> N >> C >> K;
  
  vector<int64_t> vec(N);
  
  for (int i = 0; i < N; i++) cin >> vec[i];
  
  sort(vec.begin(), vec.end());
  
  int64_t timeMemo = vec[0] + K, passenger = 0, ans = 0;
  
  for (int i = 0; i < N; i++) {
    
    if (vec[i] <= timeMemo) {
      
      passenger++;
      
      if (C < passenger) {
        ans++;
        passenger = 1;
        timeMemo = vec[i] + K;
      }
      
    }
    
    else {
      ans++;
      passenger = 1;
      timeMemo = vec[i] + K;
    }
    
    if (i == N - 1) ans++;
    
  }
  
  cout << ans << endl;
  
}