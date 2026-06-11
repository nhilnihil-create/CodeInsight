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
  int now = -1;
  int k = 2;
  int ans = 0;
  rep(i, N) {
    int a; cin >> a;
    if(a > now) {
      if(k == 2) {
        //cout << a << endl;
        ans++;
        k = 0;
      } else if(k == 0) {
        k = 1;
      }
    }
    if(a < now) {
      if(k == 1) {
        //cout << a << endl;
        ans++;
        k = 0;
      } else if(k == 0) {
        k = 2;
      }
    }
    now = a;
  }
  cout << ans << endl;

}