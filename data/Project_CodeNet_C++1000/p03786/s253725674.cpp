#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
//#define _GLIBCXX_DEBUG


signed main() {
  int N; cin >> N;
  vector<int> A(N), sum(N);
  rep(i, N) cin >> A[i];
  
  sort(all(A));
  
  sum[0] = A[0];
  rep(i, N-1) sum[i+1] = sum[i]+A[i+1];
  
  int k = N-2;
  while(2*sum[k] >= A[k+1]) {
    if(k == 0) {
      cout << N << endl;
      return 0;
    }
    k--;
  }
  cout << N-k-1 << endl;
  
}