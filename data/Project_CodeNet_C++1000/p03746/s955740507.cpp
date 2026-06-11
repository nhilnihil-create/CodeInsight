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
  int n, m;
  cin >> n >> m;
  vector<vector<int>> to(n);
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  vector<int> res = {to[0][0], 0};
  vector<bool> used(n);
  used[0] = used[to[0][0]] = true;
  rep(_, 2) {
    while (true) {
      int now = res.back();
      bool flag = true;
      for (auto next : to[now]) {
        if (!used[next]) {
          res.push_back(next);
          used[next] = true;
          flag = false;
          break;
        }
      }
      if (flag)
        break;
    }
    reverse(res.begin(), res.end());
  }
  cout << res.size() << endl;
  rep(i, res.size()) {
    if (i)
      cout << ' ';
    cout << res[i]+1;
  }
  cout << endl;
  return 0;
}