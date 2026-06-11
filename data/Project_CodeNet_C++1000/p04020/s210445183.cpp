#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define _GLIBCXX_DEBUG


signed main() {
  int N; cin >> N;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  
  int ans = 0;
  
  rep(i, N-1) {
    if((A[i]%2) * A[i+1] >= 1) {
      A[i]--;
      A[i+1]--;
      ans++;
    }
  }
  
  rep(i,N) {
    while(A[i] >= 2) {
      A[i] -= 2;
      ans++;
    }
  }
  
  
  cout << ans << endl;


}