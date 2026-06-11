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
  vector<int> a(N), b(N);
  rep(i, N) cin >> a[i] >> b[i];
  vector<int> c(M), d(M);
  rep(i, M) cin >> c[i] >> d[i];
  
  rep(i, N) {
    int k = 0;
    int dis = abs(a[i]-c[0])+abs(b[i]-d[0]);
    
    rep(j, M) {
      if(dis > abs(a[i]-c[j])+abs(b[i]-d[j])) {
        dis = abs(a[i]-c[j])+abs(b[i]-d[j]);
        k = j;
      }
    }
    
    cout << k+1 << endl;
  }
  
}
