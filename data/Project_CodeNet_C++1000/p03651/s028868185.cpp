#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define int long long
//#define _GLIBCXX_DEBUG

int gcd(int n, int m) {
  if(n < m) swap(n, m);
  if(m == 1) return 1;
  else if(m == 0) return n;
  else return gcd(m, n%m);
}

signed main() {
  int N, K; cin >> N >> K;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  
  sort(all(A));
  
  int g = gcd(A[0], A[1]);
  rep(i, N-2) g = gcd(g, A[i+2]);
  
  if(K > A[N-1]) {
    cout << "IMPOSSIBLE" << endl;
  } else if(count(all(A),K) >= 1) {
    cout << "POSSIBLE" << endl;
  } else {
  cout << (K%g == 0 ? "POSSIBLE" : "IMPOSSIBLE") << endl;
  }
  
}
