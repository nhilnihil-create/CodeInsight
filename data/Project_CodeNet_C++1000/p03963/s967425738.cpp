#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int N,K;
  cin >> N >> K;
  if(N == 1){
    cout << K << endl;
    return 0;
  }
  else if(N == 2){
    cout << K*(K-1) << endl;
    return 0;
  }
  int ans = K*(K-1);
  for(int i=0; i<N-2; i++){
    ans *= K-1;
  }
  cout << ans << endl;
}