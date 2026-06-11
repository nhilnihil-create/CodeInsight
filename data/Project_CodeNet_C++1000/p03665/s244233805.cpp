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
  int P; cin >> P;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  
  vector<int> o(N+1, 0), e(N+1, 0);
  e[0] = 1;
  rep(i, N) {
    if(A[i]%2 == 0) {
      o[i+1] = o[i] + o[i];
      e[i+1] = e[i] + e[i];
    } else {
      o[i+1] = o[i] + e[i];
      e[i+1] = o[i] + e[i];
    }
  }
  
  if(P == 0) cout << e[N] << endl;
  else cout << o[N] << endl;
}