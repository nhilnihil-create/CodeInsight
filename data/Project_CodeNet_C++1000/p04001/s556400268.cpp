#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> a;
  rep(i, n) a.push_back(s[i] - '0');
  ll ans = 0;
  rep(bit, 1<<(n-1)) {
    ll now = a[0];
    rep(i, n-1) {
      if (bit & 1<<i) {
        ans += now;
        now = 0;
      }
      now = now * 10 + a[i + 1];
    }
    ans += now;
  }
  cout << ans << endl;
  return 0;
}