#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  int q;
  cin >> s >> t >> q;
  vector<int> x(s.size()+1), y(t.size()+1);
  rep(i, s.size()) {
    x[i+1] = x[i]+1;
    if (s[i] == 'B')
      x[i+1]++;
  }
  rep(i, t.size()) {
    y[i+1] = y[i]+1;
    if (t[i] == 'B')
      y[i+1]++;
  }
  rep(i, q) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    --a, --c;
    int res = (x[b]-x[a])-(y[d]-y[c]);
    if (res%3)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}