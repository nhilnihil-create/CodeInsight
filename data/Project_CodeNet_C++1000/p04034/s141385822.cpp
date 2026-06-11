#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int N, M; cin >> N >> M;
  vector<int> x(M), y(M);
  rep(i, M) {
    cin >> x[i] >> y[i];
    x[i]--;
    y[i]--;
  }
  vector<bool> k(N, false);
  vector<int> n(N, 1);
  k[0] = true;
  
  rep(i, M) {
    if(n[x[i]] == 1) {
      if(k[x[i]]) {
        k[x[i]] = false;
        k[y[i]] = true;
        n[x[i]]--;
        n[y[i]]++;
      } else {
        n[x[i]]--;
        n[y[i]]++;
      }
    } else {
      if(k[x[i]]) {
        k[y[i]] = true;
        n[x[i]]--;
        n[y[i]]++;
      } else {
        n[x[i]]--;
        n[y[i]]++;
      }
    }
  }
  
  int ans = 0;
  rep(i, N) if(k[i]) ans++;
  cout << ans << endl;

}