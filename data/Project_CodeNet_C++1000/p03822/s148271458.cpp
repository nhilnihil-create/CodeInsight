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

vector<vector<int>> to;
int dp(int now) {
  if (!to[now].size())
    return 0;
  vector<int> res;
  for (auto next : to[now])
    res.push_back(dp(next));
  sort(res.rbegin(), res.rend());
  int mx = 0;
  rep(i, res.size()) {
    res[i] += 1+i;
    chmax(mx, res[i]);
  }
  return mx;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  to.resize(n);
  for (int i = 1; i < n; i++) {
    int a;
    cin >> a;
    --a;
    to[a].push_back(i);
  }
  int ans = dp(0);
  cout << ans << endl;
  return 0;
}