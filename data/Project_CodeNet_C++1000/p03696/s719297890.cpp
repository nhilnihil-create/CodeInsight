#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFLL = LLONG_MAX / 3;
const double eps = (1e-9);


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  string s; cin >> s;
  int n_open = 0;
  int n_close = 0;
  int count = 0;
  rep(i, s.size()) {
    if (s[i] == '(') count++;
    else if (s[i] == ')') count--;
    if (count < 0) {
      n_open -= count;
      count = 0;
    }
  }

  n_close = count;

  cout << string(n_open, '(') << s << string(n_close, ')') << endl;

  return 0;
}
