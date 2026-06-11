#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep_(i, n, m) for (int i = n; i < (int)(m); i++)
#define all(v) v.begin(), v.end()
#define int long long
#define stoi stoll
//#define _GLIBCXX_DEBUG

signed main() {
  int W, H, N; cin >> W >> H >> N;
  vector<int> x(N), y(N), a(N);
  rep(i, N) cin >> x[i] >> y[i] >> a[i];
  
  vector<vector<bool>> v(W, vector<bool>(H, true));
  rep(i, N) {
    if(a[i] == 1) {
      rep(w, W) rep(h, H) if(w < x[i]) v[w][h] = false;
    }
    if(a[i] == 2) {
      rep(w, W) rep(h, H) if(w >= x[i]) v[w][h] = false;
    }
    if(a[i] == 3) {
      rep(w, W) rep(h, H) if(h < y[i]) v[w][h] = false;
    }
    if(a[i] == 4) {
      rep(w, W) rep(h, H) if(h >= y[i]) v[w][h] = false;
    }
  }
  
  int ans = 0;
  rep(w, W) rep(h, H) if(v[w][h]) ans++;
  cout << ans << endl;

}
