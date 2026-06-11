#include <bits/stdc++.h>
using namespace std;

int main(){ 
  int N, K;
  vector<int64_t> A(20), highest(20, 0);

  cin >> N >> K;
  for(int i=1; i<=N; i++){
    cin >> A[i];
    highest[i] = max(highest[i-1], A[i]);
  }

  int64_t ans = 1e15;
  for(int bits=0; bits<(1<<N); bits++){
    if(bitset<20>(bits).count() != K) continue;

    vector<int64_t> B = highest; int64_t cur = 0;
    for(int i=1; i<=N; i++){
      if(bits >> (i-1) & 1){
        if(A[i] <= B[i-1]){
          cur += B[i-1]-A[i]+1;
          B[i] = B[i-1]+1;
        }
      } else {
        B[i] = max(B[i-1], A[i]);
      } 
    }
    ans = min(ans, cur);
  }
  cout << ans << endl;
}