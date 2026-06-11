#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int N; cin >> N;
  vector<int> A(N), B(N);
  rep(i, N) cin >> A[i] >> B[i];
  
  reverse(all(A));
  reverse(all(B));
  
  int ans = 0;
  rep(i, N) {
    A[i] += ans;
    if(A[i]%B[i] == 0) continue;
    ans += B[i] - A[i]%B[i];
  }
  
  cout << ans << endl;
  
}
