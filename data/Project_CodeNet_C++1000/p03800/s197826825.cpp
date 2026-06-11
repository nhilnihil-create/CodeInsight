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
const long long INFL = 1LL<<60;

bool check(string s, vector<bool>& ans) {
  for (int i = 1; i < s.size() - 1; i++) {
    if ((ans[i] && s[i] == 'o') || (!ans[i] && s[i] == 'x')) {
      ans[i+1] = ans[i-1];
    } else {
      ans[i+1] = !ans[i-1];
    }
  }
  if ((ans.back() && s.back() == 'o') || (!ans.back() && s.back() == 'x')) {
    if (ans[ans.size() - 2] != ans[0]) return false;
  } else {
    if (ans[ans.size() - 2] == ans[0]) return false;
  }
  if ((ans[0] && s[0] == 'o') || (!ans[0] && s[0] == 'x')) {
    if (ans[1] == ans.back()) return true;
    else return false;
  } else {
    if (ans[1] == ans.back()) return false;
    else return true;
  }
}


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  string s; cin >> s;

  for (int i = 0; i < 4; i++) {
    vector<bool> ans(n, false);
    ans[0] = ((i>>0) & 1);
    ans[1] = ((i>>1) & 1);
    if (check(s, ans)) {
      for (bool x : ans) {
        if (x) cout << "S";
        else cout << "W";
      }
      cout << endl;
      return 0;
    }
  }

  cout << "-1" << endl;

  return 0;
}
