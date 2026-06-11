#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
using namespace std;

using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1e9;
const long long INFLL = 1LL<<60;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  int ans = 0;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] != s[i-1]) ans++;
  }

  cout << ans << endl;

  return 0;
}
