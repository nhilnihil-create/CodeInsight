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

int count(string s) {
  set<char> a;
  for (char c : s) a.insert(c);
  return a.size();
}

int calc(string s, char t) {
  int n = 0;
  while (count(s) > 1) {
    n++;
    rep(i, s.size()-1) {
      if (s[i+1] == t) s[i] = t;
    }
    s.pop_back();
  }
  return n;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;

  int ans = INF;

  for (char c = 'a'; c <= 'z'; c++) {
    if (s.find(c) == string::npos) continue;
    chmin(ans, calc(s, c));
  }

  cout << ans << endl;

  return 0;
}
