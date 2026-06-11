#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG



signed main() {
  int N, C, K; cin >> N >> C >> K;
  vector<int> T(N);
  rep(i, N) cin >> T[i];
  
  sort(all(T));
  
  int ans = 0;
  int n = 0;
  
  while(true) {
    if(n == N) break;
    ans++;
    int k = 0;
    int t = T[n]+K;
    while(n+k < N && k < C && T[n+k] <= t) k++;
    n += k;
  }

  cout << ans << endl;
}
